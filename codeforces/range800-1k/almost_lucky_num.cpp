#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_set>
#include <algorithm>

class Problem {
public:
  void solve() {
    int n;
    std::cin >> n;
    
    bool is_lucky = is_lucky_num(n);

    if (n < 4) {
      std::cout << "NO" << std::endl;
      return;
    }

    if (is_lucky) {
      std::cout << "YES" << std::endl;
      return;
    }
    
    if (n % 4 == 0 || n % 7 == 0 || n % 47 == 0 || n % 74 == 0) {
      std::cout << "YES" << std::endl;
      return;
    }
    std::cout << "NO" << std::endl;
  }

  bool is_lucky_num(int n) {
    int last_num = 0;
    while (n > 1) {
      last_num = n % 10;
      if (last_num != 4 && last_num != 7) {
        return false;
      }
      n = n / 10;
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
