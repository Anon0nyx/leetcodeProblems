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

    for (int i = 0; i < n; i++) {
      std::string parens;
      std::cin >> parens;
      
      int open = 0;
      int hit = 0;
      bool bol = false;

      for (auto it : parens) {
        if (open == 0 && bol) {
          std::cout << "YES" << std::endl;
          hit = 1;
          break;
        }
        if (it == '(') {
          open += 1;
        } else {
          open -= 1;
        }
        bol = true;
      }
      if (hit == 0)
        std::cout << "NO" << std::endl;
    }
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  Problem problem;
  problem.solve();
}
