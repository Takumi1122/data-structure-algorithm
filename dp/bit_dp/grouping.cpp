#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    Educational DP Contest U - Grouping
      https://atcoder.jp/contests/dp/tasks/dp_u
*/

int a[20][20];
ll dp[1 << 16];

int main() {
  int n;
  cin >> n;
  rep(i, n) rep(j, n) cin >> a[i][j];

  for (int s = 1; s < 1 << n; s++) {
    rep(i, n) rep(j, i) if (s >> i & s >> j & 1) dp[s] += a[i][j];

    for (int t = s; t > 0; t = t - 1 & s) {
      if (t == s) continue;
      dp[s] = max(dp[s], dp[t] + dp[s ^ t]);
    }
  }

  cout << dp[(1 << n) - 1] << endl;
  return 0;
}