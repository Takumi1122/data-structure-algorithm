#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 確率DP

/*
    参考リンク
    Educational DP Contest I - Coins
      https://atcoder.jp/contests/dp/tasks/dp_i
*/

double dp[3100][3100];

int main() {
  int n;
  cin >> n;
  vector<double> p(n);
  rep(i, n) cin >> p[i];

  dp[0][0] = 1;
  rep(i, n) {
    rep(j, n + 1) {
      dp[i + 1][j + 1] += dp[i][j] * p[i];
      dp[i + 1][j] += dp[i][j] * (1 - p[i]);
    }
  }

  double ans = 0;
  for (int j = n / 2 + 1; j <= n; ++j) ans += dp[n][j];
  printf("%.15f\n", ans);
  return 0;
}