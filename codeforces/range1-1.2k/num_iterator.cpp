#include <iostream>

int main() {
  int val = 12345;
  while (val >= 1) {
    int temp_val = val % 10;
    std::cout << temp_val << std::endl;
    val /= 10;
  }
  return 0;
}
