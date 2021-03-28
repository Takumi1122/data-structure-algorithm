#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// orとxorの単位元は 0
// 数列を仕切りで区切る

/*
    参考リンク
    ABC 197 C - ORXOR
      https://atcoder.jp/contests/abc197/tasks/abc197_c
*/

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  int ans = 1 << 30;
  rep(bit, 1 << (n - 1)) {
    int now = 0;
    int o = 0;
    rep(i, n) {
      o |= a[i];
      if (bit & (1 << i)) {
        now ^= o;
        o = 0;
      }
    }
    now ^= o;
    ans = min(ans, now);
  }

  cout << ans << endl;
  return 0;
}