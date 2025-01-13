#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <atomic>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <random>
#include <memory>
#include <cstring>
#include <string>
#include <sstream>

// Struct to hold different operation counters
struct BenchmarkCounters {
	std::atomic<uint64_t> floating_point_ops{ 0 };
	std::atomic<uint64_t> integer_ops{ 0 };
	std::atomic<uint64_t> memory_bandwidth_bytes{ 0 };
};

BenchmarkCounters counters;

// Memory buffer size for bandwidth testing (256 MB per thread)
constexpr size_t BUFFER_SIZE = 256 * 1024 * 1024;

enum class BenchmarkType {
	FloatingPoint,
	Integer,
	Memory
};

// Function to perform floating-point operations
void floating_point_test(int seconds) {
	auto start = std::chrono::steady_clock::now();
	uint64_t local_operations = 0;

	while (true) {
		double result = 1.0;
		for (int i = 0; i < 1000; ++i) {
			// Mix of trigonometric, logarithmic, and exponential operations
			result = std::sqrt(result + 2.0) * std::sin(result);
			result = std::log(std::abs(result) + 1.0) + std::exp(result * 0.1);
			result = std::cos(result) * std::tan(result * 0.1);
			local_operations += 6; // Count major operations
		}

		auto now = std::chrono::steady_clock::now();
		if (std::chrono::duration_cast<std::chrono::seconds>(now - start).count() >= seconds) {
			break;
		}
	}

	counters.floating_point_ops += local_operations;
}

// Function to perform integer operations
void integer_test(int seconds) {
	auto start = std::chrono::steady_clock::now();
	uint64_t local_operations = 0;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(1, 1000000);

	while (true) {
		uint64_t result = 1;
		for (int i = 0; i < 1000; ++i) {
			// Mix of multiplication, division, and bitwise operations
			result *= dis(gen);
			result /= (dis(gen) % 100 + 1);
			result ^= dis(gen);
			result = (result << 3) | (result >> 3);
			local_operations += 4; // Count major operations
		}

		auto now = std::chrono::steady_clock::now();
		if (std::chrono::duration_cast<std::chrono::seconds>(now - start).count() >= seconds) {
			break;
		}
	}

	counters.integer_ops += local_operations;
}

struct MemBuffer {
	int duration;
	char* buffer1;
	char* buffer2;
	MemBuffer(int duration, char* buffer1, char* buffer2) {
		this->duration = duration;
		this->buffer1 = buffer1;
		this->buffer2 = buffer2;
	}
};

std::vector<MemBuffer*> mem_buffers;

// Function to test memory bandwidth
void memory_bandwidth_test(int index) {
	auto start = std::chrono::steady_clock::now();
	uint64_t local_bytes_transferred = 0;

	auto params = mem_buffers[index];

	while (true) {
		// Sequential read and write
		std::memcpy(params->buffer2, params->buffer1, BUFFER_SIZE);
		// Random access pattern
		for (size_t i = 0; i < BUFFER_SIZE; i += 4096) {
			params->buffer2[i] = params->buffer1[BUFFER_SIZE - i - 1];
		}

		local_bytes_transferred += BUFFER_SIZE * 2; // Count both read and write

		auto now = std::chrono::steady_clock::now();
		if (std::chrono::duration_cast<std::chrono::seconds>(now - start).count() >= params->duration) {
			break;
		}
	}

	counters.memory_bandwidth_bytes += local_bytes_transferred;
}

// Function to format large numbers with commas
std::string format_with_commas(uint64_t value) {
	std::string numStr = std::to_string(value);
	int insertPosition = numStr.length() - 3;
	while (insertPosition > 0) {
		numStr.insert(insertPosition, ",");
		insertPosition -= 3;
	}
	return numStr;
}

// Function to format bandwidth in human-readable form
std::string format_bandwidth(double bytes_per_sec) {
	const char* units[] = { "B/s", "KB/s", "MB/s", "GB/s" };
	int unit = 0;

	while (bytes_per_sec >= 1024.0 && unit < 3) {
		bytes_per_sec /= 1024.0;
		unit++;
	}

	std::stringstream ss;
	ss << std::fixed << std::setprecision(2) << bytes_per_sec << " " << units[unit];
	return ss.str();
}

int main() {
	unsigned int max_threads = std::thread::hardware_concurrency();
	std::cout << "System has " << max_threads << " hardware threads available\r\n\r\n";

	int num_threads;
	std::cout << "Enter number of threads to use (1-" << max_threads << "): ";
	std::cin >> num_threads;

	if (num_threads < 1 || num_threads > static_cast<int>(max_threads)) {
		std::cout << "Invalid number of threads. Using 1 thread.\r\n";
		num_threads = 1;
	}

	int duration;
	std::cout << "Enter test duration in seconds: ";
	std::cin >> duration;

	if (duration < 1) {
		std::cout << "Invalid duration. Using 10 seconds.\r\n";
		duration = 10;
	}

	int test_type;
	std::cout << "\r\nSelect benchmark type:\r\n"
		<< "1. Floating-point operations\r\n"
		<< "2. Integer operations\r\n"
		<< "3. Memory bandwidth\r\n"
		<< "Choice: ";
	std::cin >> test_type;

	BenchmarkType benchmark_type;
	switch (test_type) {
	case 1: benchmark_type = BenchmarkType::FloatingPoint; break;
	case 2: benchmark_type = BenchmarkType::Integer; break;
	case 3:
		benchmark_type = BenchmarkType::Memory;
		for (int i = 0; i < num_threads; ++i) {
			mem_buffers.push_back(new MemBuffer(duration, new char[BUFFER_SIZE], new char[BUFFER_SIZE]));
		}
		break;
	default: benchmark_type = BenchmarkType::Integer; break;
	}

	std::vector<std::thread> threads;
	std::cout << "\r\nStarting benchmark...\r\n";

	auto start_time = std::chrono::steady_clock::now();

	// Launch threads based on selected benchmark type
	for (int i = 0; i < num_threads; ++i) {
		switch (benchmark_type) {
		case BenchmarkType::FloatingPoint:
			threads.emplace_back(floating_point_test, duration);
			break;
		case BenchmarkType::Integer:
			threads.emplace_back(integer_test, i);
			break;
		case BenchmarkType::Memory:
			threads.emplace_back(memory_bandwidth_test, duration);
			break;
		}
	}

	for (auto& thread : threads) {
		thread.join();
	}

	auto end_time = std::chrono::steady_clock::now();
	auto elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>(
		end_time - start_time).count();

	// Calculate and display results
	std::cout << "\r\nBenchmark Results:\r\n";
	std::cout << "================\r\n";

	if (benchmark_type == BenchmarkType::FloatingPoint) {
		double fp_ops_per_second = static_cast<double>(counters.floating_point_ops) / elapsed_seconds;
		std::cout << "Floating-point Operations/Second: " << format_with_commas(static_cast<uint64_t>(fp_ops_per_second)) << "\r\n";
	}

	if (benchmark_type == BenchmarkType::Integer) {
		double int_ops_per_second = static_cast<double>(counters.integer_ops) / elapsed_seconds;
		std::cout << "Integer Operations/Second: " << format_with_commas(static_cast<uint64_t>(int_ops_per_second)) << "\r\n";
	}

	if (benchmark_type == BenchmarkType::Memory) {
		double bandwidth = static_cast<double>(counters.memory_bandwidth_bytes) / elapsed_seconds;
		std::cout << "Memory Bandwidth: " << format_bandwidth(bandwidth) << "\r\n";
	}
	
	for (auto membuf : mem_buffers) {
		delete membuf;
	}

	return 0;
}