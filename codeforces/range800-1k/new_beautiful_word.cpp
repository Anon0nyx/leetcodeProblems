#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

class Problem {
public:
  void solve() {
    int test_case_count;
    std::cin >> test_case_count;

    for (int test = 0; test < test_case_count; test++) {
      int string_length;
      std::string binary_string;
      std::cin >> string_length >> binary_string;

      int max_subsequence_size = -1;
      std::vector<int> best_subsequence_indices;

      for (int mask = 0; mask < (1 << string_length); mask++) {
        std::vector<int> selected_indices;
        std::string subsequence = "", remaining_string = "";

        for (int pos = 0; pos < string_length; pos++) {
          if (mask & (1 << pos)) {
            subsequence += binary_string[pos];
            selected_indices.push_back(pos + 1); // 1-based indexing
          } else {
            remaining_string += binary_string[pos];
          }
        }

        if (std::is_sorted(subsequence.begin(), subsequence.end()) && is_palindrome(remaining_string)) {
          if ((int)selected_indices.size() > max_subsequence_size) {
            max_subsequence_size = selected_indices.size();
            best_subsequence_indices = selected_indices;
          }
        }
      }

      if (max_subsequence_size == -1) {
        std::cout << -1 << std::endl;
      } else {
        std::cout << max_subsequence_size << std::endl;
        for (int i = 0; i < best_subsequence_indices.size(); i++) {
          std::cout << best_subsequence_indices[i] << (i + 1 == best_subsequence_indices.size() ? "\n" : " ");
        }
      }
    }
  }

  bool is_palindrome(const std::string& input_string) {
    int left = 0, right = input_string.size() - 1;
    while (left < right) {
      if (input_string[left] != input_string[right]) return false;
      left++; right--;
    }
    return true;
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  Problem problem;
  problem.solve();
}
