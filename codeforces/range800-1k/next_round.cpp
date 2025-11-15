#include <bits/stdc++.h>
#include <iostream>
#include <vector>

void solve() 
{
  int n;
  int k;
  std::vector<int> scores;
  std::cin >> n >> k;
  int going_to_nr = 0;
  
  for (int i=0; i < n; i++) {
    int x;
    std::cin >> x;
    if (x > 0)
      scores.push_back(x);
  }

  if (scores.size() == 0) {
    std::cout << 0 << std::endl;
    return;
  } else if (scores.size() <= k) {
    std::cout << scores.size() << std::endl;
    return;
  }
  
  int score_to_beat = scores[k-1];
  for (auto score : scores) {
    if (score >= score_to_beat) {
      going_to_nr++;
    }
  }

  std::cout << going_to_nr << std::endl;
}

int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  solve();
}
