#include <bits/stdc++.h>
#include <iostream>
#include <vector>

int find_min_trips(int group_cnt, std::vector<int> groups) 
{
  int min_trips = 0;
  std::unordered_map<int, int> taxi_groups;
  for (int i = 0; i < groups.size(); i++) {
    taxi_groups[groups[i]]++;
  }

  min_trips += taxi_groups[4];

  int pairs = std::min(taxi_groups[3], taxi_groups[1]);

  min_trips += pairs;
  taxi_groups[3] -= pairs;
  taxi_groups[1] -= pairs;

  min_trips += taxi_groups[3];
  
  min_trips += taxi_groups[2] / 2;
  if (taxi_groups[2] % 2) {
    min_trips += 1;
    taxi_groups[1] = std::max(0, taxi_groups[1]-2);
  }

  if (taxi_groups[1] > 0)
    min_trips += (taxi_groups[1] + 3) / 4;

  return min_trips;
}

void solve() 
{
  int n;
  std::vector<int> groups;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    int val;
    std::cin >> val;
    groups.push_back(val);
  }
  std::cout << find_min_trips(n, groups) << std::endl;
}

int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  solve();
}
