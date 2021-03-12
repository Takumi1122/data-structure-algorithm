#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int a, b, x, y;
  cin >> a >> b >> x >> y;
  if (a > b) {
    int ans = min((a - b - 1) * y + x, (2 * (a - b) - 1) * x);
    cout << ans << endl;
  } else if (a == b) {
    cout << x << endl;
  } else {
    int ans = min((b - a) * y + x, (2 * (b - a) + 1) * x);
    cout << ans << endl;
  }
  return 0;
}