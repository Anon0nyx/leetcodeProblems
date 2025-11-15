#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

void solve() {
  int n;
  cin >> n;
  // Your code here
  int res = (n % 2 == 0);
  if (res && n > 3) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
}
