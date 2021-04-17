#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

/*
    参考リンク
    ABC 198 C - Compass Walking
      https://atcoder.jp/contests/abc198/tasks/abc198_c
*/

int main() {
  ll r, x, y;
  cin >> r >> x >> y;
  if (r * r == x * x + y * y) {
    cout << 1 << endl;
    return 0;
  }
  if (r * r > x * x + y * y) {
    cout << 2 << endl;
    return 0;
  }

  double d = sqrt(x * x + y * y);
  ll ans = ceil(d / (double)r);
  cout << ans << endl;
  return 0;
}