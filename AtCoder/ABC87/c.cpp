#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int dp[2][105];

int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(2, vector<int>(n + 1));
  rep(i, 2) rep(j, n) cin >> a[i][j];

  dp[0][0] = a[0][0];
  rep(i, 2) rep(j, n) {
    if (i == 0) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + a[i + 1][j]);
    dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + a[i][j + 1]);
  }

  cout << dp[1][n - 1] << endl;
  return 0;
}