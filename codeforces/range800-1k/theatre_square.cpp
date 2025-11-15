#include <bits/stdc++.h>
#include <iostream>
#include <vector>

void solve() 
{
  int n;
  int m;
  int a;

  std::cin >> n >> m >> a;

  long long n_tiles = (n + a - 1) / a;
  long long m_tiles = (m + a - 1) / a;
  long long total_tiles = n_tiles * m_tiles;

  std::cout << total_tiles << std::endl;
}

int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  solve();
}
