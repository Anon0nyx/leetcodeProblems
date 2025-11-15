#include <bits/stdc++.h>
#include <iostream>
#include <vector>

void solve() 
{
  int n;
  std::vector<std::string> words;
  std::cin >> n;

  int problems_to_solve = 0;
  for (int i=0; i < n; i++) {
    int x;
    int y;
    int z;
    std::cin >> x >> y >> z;
    int confidence = x + y + z;
    if (confidence >= 2) {
      problems_to_solve++;
    }
  }
  std::cout << problems_to_solve << std::endl;
}

int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  solve();
}
