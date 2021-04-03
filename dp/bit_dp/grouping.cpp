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

int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  rep(i, n) rep(j, n) cin >> a[i][j];

  int n2 = 1 << n;
  vector<ll> dp(n2);

  rep(s, n2) {
    rep(i, n) rep(j, i) if (s >> i & s >> j & 1) dp[s] += a[i][j];
    // sの部分集合を調べる
    for (int t = s; t > 0; t = (t - 1) & s) {
      if (t == s) continue;
      dp[s] = max(dp[s], dp[t] + dp[s ^ t]);
    }
  }

  cout << dp[n2 - 1] << endl;
  return 0;
}