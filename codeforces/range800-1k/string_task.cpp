#include <string>
#include <iostream>
#include <unordered_map>

class Solution {
  public:
  void solve() {
    std::string word;
    std::cin >> word;
    
    std::unordered_map<char, int> vowels;
    vowels['a'] = 1;
    vowels['y'] = 1;
    vowels['e'] = 1;
    vowels['i'] = 1;
    vowels['o'] = 1;
    vowels['u'] = 1;

    std::string new_word = "";  

    for (char letter : word) {
      letter = std::tolower(letter);
      if (vowels[letter] == 0) {
        new_word += '.';
        new_word += letter;
      }
    }
    std::cout << new_word << std::endl;
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  Solution problem;
  problem.solve();
}
