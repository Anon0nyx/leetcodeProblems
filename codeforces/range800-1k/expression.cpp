#include <iostream>
#include <vector>

void solve() 
{
  int x, y, z;
  std::cin >> x >> y >> z;

  int max = x + y + z;
  if (x * y * z > max) max = x * y * z;
  if (x * (y + z) > max) max = x * (y + z);
  if (x + (y * z) > max) max = x + (x * z);
  if ((x+y) * z > max) max = (x + y) * z;

  std::cout << max << std::endl;
}

int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  solve();
}
