#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
  ll x, y, a, b;
  cin >> x >> y >> a >> b;

  ll ans = 0;
  while (1) {
    // オーバーフロー対策
    if (y / a < x) break;
    if (a * x >= y) break;
    if (a * x >= x + b) break;
    x *= a;
    ++ans;
  }

  ans += (y - 1 - x) / b;
  cout << ans << endl;
  return 0;
}