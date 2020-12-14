#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 185 E - Sequence Matching
      https://atcoder.jp/contests/abc185/tasks/abc185_e
*/

void chmin(int &a, int b) {
  if (a > b) a = b;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];

  const int INF = 1 << 29;
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
  dp[0][0] = 0;

  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      // A の末尾を削除
      if (i > 0) chmin(dp[i][j], dp[i - 1][j] + 1);

      // B の末尾を削除
      if (j > 0) chmin(dp[i][j], dp[i][j - 1] + 1);

      // A の末尾と B の末尾を対応させる
      if (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1])
          chmin(dp[i][j], dp[i - 1][j - 1]);
        else
          chmin(dp[i][j], dp[i - 1][j - 1] + 1);
      }
    }
  }

  cout << dp[n][m] << endl;
  return 0;
}