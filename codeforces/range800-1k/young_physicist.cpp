#include <string>
#include <iostream>
#include <unordered_map>

class Solution {
  public:
  void solve() {
    int n;
    std::cin >> n;
    
    signed int total_x=0, total_y=0, total_z=0;
    for (int i = 0; i < n; i++) {
      int x, y, z;
      std::cin >> x >> y >> z;
      
      total_x += x;
      total_y += y;
      total_z += z;
    }
    //int total = total_x + total_y + total_z;
    if (total_x == 0 && total_y == 0 && total_z ==0) { 
      std::cout << "YES" << std::endl;
      return;
    }
    std::cout << "NO" << std::endl;
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  Solution problem;
  problem.solve();
}
