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
  
 /*
      int hit = 0;
      for (int i = 0; i < parens.size(); i++) {
        if (parens[i] != '(') continue;
        for (int j = i + 1; j < parens.size(); j++) {
          if (parens[j] != ')') continue;
          std::string new_parens;
          for (int k = 0; k < parens.size(); k++ ) {
            if (k != j && k != i) {
              new_parens += parens[k];
            }
          }
          if (!verify_parens(new_parens)) {
            hit = 1;
            break;
          }
          new_parens = "";
        }
      }
*/

      int hit = 0;
      for (int l = 0; l < parens.size(); ++l) {
        if (parens[l] != '(') continue;
        if (hit == 1) break;
        for (int r = l + 1; r < parens.size(); ++r) {
          if (parens[r] != ')') continue;
          std::string new_parens = "";
          for (int i = 0; i < parens.size(); ++i)
            if (i != r && i != l)
              new_parens += parens[i];
          if (!verify_parens(new_parens)) {
            hit = 1;
            break;
          }
        }
      }

      if (!hit) {
        std::cout << "NO" << std::endl;
      } else {
        std::cout << "YES" << std::endl;
      }
    }
  }

  bool verify_parens(std::string s) {
    int balance = 0;
    for (char paren : s) {
      if (paren == '(') {
        ++balance;
      } else if (paren == ')') {
        --balance;
        if (balance < 0) return false;
      } else {
        return false;
      }
    }
    return balance == 0;
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  Problem problem;
  problem.solve();
}
