#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  int mn = min(x, y);
  int ab = abs(x - y);
  int ans = 0;

  if (a >= 2 * c && b >= 2 * c) {
    ans += c * 2 * max(x, y);
    cout << ans << endl;
    return 0;
  }

  if (a + b >= 2 * c) {
    if (x >= y) {
      ans += mn * 2 * c;
      if (a >= 2 * c) {
        ans += 2 * c * ab;
      } else {
        ans += ab * a;
      }
    } else {
      ans += mn * 2 * c;
      if (b >= 2 * c) {
        ans += 2 * c * ab;
      } else {
        ans += ab * b;
      }
    }
  } else {
    ans += x * a + y * b;
  }

  cout << ans << endl;
  return 0;
}