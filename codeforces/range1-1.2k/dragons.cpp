#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Problem {
public:
  std::string solve() {
    int dragon_cnt, power;
    std::cin >> power >> dragon_cnt;

    std::vector<std::pair<int, int>> dragons;
    
    for (int i = 0; i < dragon_cnt; i++) {
      int xi, yi;
      std::cin >> xi >> yi;
      dragons.push_back({xi, yi});
    }
    
    std::sort(dragons.begin(), dragons.end());
    for (std::pair<int, int> dragon : dragons) {
      if (power <= dragon.first) return "NO";
      power += dragon.second;
    }
    return "YES";
  }
};

int main() {
  Problem problem;
  std::cout << problem.solve() << std::endl;

  return 0;
}
