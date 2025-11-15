#include <bits/stdc++.h>
#include <iostream>
#include <vector>

std::string abbr_string(std::string word)
{
  int len_w = word.size() - 2;
  std::string len_word = "";
  char num = 0;
  while(len_w >= 1) {
    num = len_w % 10;
    len_w /= 10;
    char letter = '0' + num;
    len_word += letter;
  }
  std::reverse(len_word.begin(), len_word.end());
  std::string new_word = "";
  new_word += word.front();
  new_word += len_word;
  new_word += word.back();
  return new_word;
}

void solve() 
{
  int n;
  std::vector<std::string> words;
  std::vector<std::string> abbr_words;

  std::cin >> n;
  
  for (int i=0; i < n; i++) {
    std::string word;
    std::cin >> word;
    words.push_back(word); 
  }
  
  for (std::string word : words) {
    if (word.size() <= 10 || word.size() <= 2) {
      abbr_words.push_back(word);
    } else {
      std::string new_word = abbr_string(word);
      abbr_words.push_back(new_word);
    }
  }
  for (std::string word : abbr_words) {
    std::cout << word << std::endl;
  }
}

int main() 
{
  solve();
}
