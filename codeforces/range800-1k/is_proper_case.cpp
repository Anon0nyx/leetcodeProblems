#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_set>
#include <algorithm>

class Problem {
public:
  bool is_upper(char letter) {
    if (int(letter) > 64 && int(letter) < 91) {
      return true;
    }
    return false;
  }

  std::string all_to_lower(std::string word) {
    std::string new_word = "";
    for (auto letter : word) {
      new_word += make_lower(letter);
    }
    return new_word;
  }

  char make_lower(char upper_char) {
    return char(int(upper_char) + 32);
  }

  char make_upper(char lower_char) {
    return char(int(lower_char) - 32);
  }

  bool all_upper(std::string word) {
    for (auto letter : word) {
      if (!is_upper(letter)) return false;
    }
    return true;
  }

  std::string fixed_word(std::string word) {
    std::string new_word = "";
    for (int i = 0; i < word.size(); ++i) {
      if (i == 0 && !is_upper(word[i])) {
        new_word += make_upper(word[i]);
      } else if (is_upper(word[i]) && i > 0) {
        new_word += make_lower(word[i]);
      } else {
        new_word += word[i];
      }
    }
    return new_word;
  }

  void solve() {
    std::string word;
    std::cin >> word;

    if (word.size() == 1) {
      if (!is_upper(word[0])) {
        std::cout << make_upper(word[0]) << std::endl;
        return;
      }
    }

    if (all_upper(word)) {
      std::cout << all_to_lower(word) << std::endl;
      return;
    }

    if (!is_upper(word[0]) && all_upper(word.substr(1))) {
      std::cout << fixed_word(word) << std::endl;
      return;
    }
    
    std::cout << word << std::endl;
    return;
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  Problem problem;
  problem.solve();
}
