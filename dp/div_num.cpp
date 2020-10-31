#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 蟻本P66: 分割数

int main() {
  int n, m, M;
  cin >> n >> m >> M;
  // dp[i][j]: iのj分割の総数
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  dp[0][0] = 1;
  for (int i = 0; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (i - j >= 0) {
        dp[i][j] = (dp[i][j - 1] + dp[i - j][j]) % M;
      } else {
        dp[i][j] = dp[i][j - 1];
      }
    }
  }

  cout << dp[n][m] << endl;
}