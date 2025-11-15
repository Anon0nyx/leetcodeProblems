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
      int left = 0, right = 1;
      int length;
      std::string word;

      std::cin >> length >> word;
      std::string sub_word;
      int biggest_result = 0;
      std::vector<int> idx_store;

      while (right < length) {
        int right_digit = word[right] - '0';
        int left_digit = word[left] - '0';

        if (left_digit <= right_digit) {
          idx_store.push_back(right + 1);
          if (check_palindrome(idx_store, word)) {
            if (idx_store.size() > biggest_result) {
              biggest_result = idx_store.size();
            }
          } else {
            idx_store.pop_back();
            left = right;
          }
          right++;
        } else {
          if (idx_store.size() > biggest_result) {
            biggest_result = idx_store.size();
          }
          idx_store.clear();
          left = right;
          right++;
        }
      }

      std::cout << biggest_result << std::endl;
      if (!idx_store.empty()) {
        for (int i = 0; i < idx_store.size() - 1; i++) {
          std::cout << idx_store[i] << " ";
        }
        std::cout << idx_store.back() << std::endl;
      }
    }
  }

  bool check_palindrome(const std::vector<int>& substr, const std::string& word) {
    std::string new_word = "";

    for (auto it : substr){
      std::cout << it << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < word.size(); i++) {
      if (std::find(substr.begin(), substr.end(), i + 1) == substr.end()) {
        new_word += word[i];
      }
    }
    return is_palindrome(new_word);
  }

  bool is_palindrome(const std::string& word) {
    std::stack<char> s;
    int n = word.size();

    if (word.empty()) return true;

    for (int i = 0; i < n / 2; i++)
      s.push(word[i]);

    int start = (n % 2 == 0) ? n / 2 : n / 2 + 1;

    for (int i = start; i < n; i++) {
      if (s.empty() || s.top() != word[i])
        return false;
      s.pop();
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
