#include <bits/stdc++.h>
#include <iostream>
#include <vector>

void solve() 
{
  int n;
  int final_x = 0;
  std::vector<std::string> words;
  std::cin >> n;

  for (int i=0; i < n; i++) {
    std::string word;
    std::cin >> word;
    words.push_back(word); 
  }
  
  for (std::string word : words) {
    if (word.find('-') != std::string::npos) {
      --final_x;
    } else {
      ++final_x;
    }
  }
  std::cout << final_x << std::endl;
}

int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  solve();
}
