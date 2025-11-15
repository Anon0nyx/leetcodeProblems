#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_set>
#include <algorithm>

class Problem {
public:
  void solve() {
    std::string word;
    std::cin >> word;
    
    std::vector<char> hello = {'h','e','l','l','o'};
    std::stack<char> hello_stack;
    
    int idx = 0;

    for (int i = 0; idx < 5 && i < word.size(); i++) {
      if (word[i] == hello[idx]) {
        hello_stack.push(word[i]);
        idx++;
      }
    }
    if (hello_stack.size() == hello.size()) {
      std::cout << "YES" << std::endl;
      return;
    }
    std::cout << "NO" << std::endl;
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  Problem problem;
  problem.solve();
}
