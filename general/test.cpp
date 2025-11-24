#include <iostream>

int main() {
  int val = int('A');
  std::cout << char(char(val) - (char(val) - char('a'))) << std::endl;

  return 0;
}
