#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, t;
  cin >> n >> t;
  vector<P> ab;
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    ab.push_back(make_pair(a, b));
  }

  vector<vector<int> > dp(n + 1, vector<int>(t));
  vector<vector<int> > prev_dp(n + 1, vector<int>(t));
  rep(i, t) dp[0][i] = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= t - 1; j++) {
      if (j >= ab[i].first) {
        if (dp[i][j - ab[i].first] + ab[i].second > dp[i][j]) {
          dp[i + 1][j] = dp[i][j - ab[i].first] + ab[i].second;
          prev_dp[i + 1][j] = j - ab[i].first;
        }
      }

      if (dp[i + 1][j] < dp[i][j]) {
        dp[i + 1][j] = dp[i][j];
        prev_dp[i + 1][j] = j;
      }
    }
  }

  int mx = 0;
  int cur_t = t - 1;
  for (int i = n - 1; i >= 0; --i) {
    if (prev_dp[i + 1][cur_t] != cur_t - ab[i].first) {
      mx = max(mx, ab[i].second);
    }
    cur_t = prev_dp[i + 1][cur_t];
  }

  cout << dp[n][t - 1] + mx << endl;
  return 0;
}