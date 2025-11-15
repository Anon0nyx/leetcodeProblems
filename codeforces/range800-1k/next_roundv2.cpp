#include <bits/stdc++.h>
#include <iostream>
#include <vector>

void solve() 
{
  int n;
  int k;
  int going_to_nr = 0;
  int score_to_beat = 0;
 
  std::cin >> n >> k;

  for (int i = 0; i < n; i++) {
    int score;
    std::cin >> score;
    if (score >= score_to_beat && score != 0) {
      going_to_nr++;
    }
    if (i == k-1)
      score_to_beat = score;
  }

  std::cout << going_to_nr << std::endl;
}

int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  solve();
}
