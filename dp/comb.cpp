#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 蟻本P67: 重複組み合わせ

int main() {
  int n, m, M;
  cin >> n >> m >> M;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  // dp[i + 1][j]: i番目までの品物からj個選ぶ組み合わせの総数
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  rep(i, n + 1) dp[i][0] = 1;

  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= m; j++) {
      if (j - 1 - a[i] >= 0) {
        dp[i + 1][j] =
            (dp[i + 1][j - 1] + dp[i][j] - dp[i][j - 1 - a[i]] + M) % M;
      } else {
        dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j]) % M;
      }
    }
  }

  cout << dp[n][m] << endl;
}