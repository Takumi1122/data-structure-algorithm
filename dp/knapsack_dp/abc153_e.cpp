#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 個数制限なしナップサック
// 最小化

int main() {
  int h, n;
  cin >> h >> n;
  vector<int> a(n);
  vector<int> b(n);
  rep(i, n) cin >> a[i] >> b[i];

  vector<vector<int>> dp(n + 1, vector<int>(h + 1, 100000000));
  dp[0][0] = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= h; j++) {
      if (j <= a[i]) {
        dp[i + 1][j] = min(dp[i][j], b[i]);
      } else {
        dp[i + 1][j] = min(dp[i][j], dp[i + 1][j - a[i]] + b[i]);
      }
    }
  }

  cout << dp[n][h] << endl;
  return 0;
}