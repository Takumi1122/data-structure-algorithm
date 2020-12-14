#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// o(|s| * |t|) レーベンシュタイン距離 (diffコマンド)

void chmin(int &a, int b) {
  if (a > b) a = b;
}

const int INF = 1 << 29;
int dp[1010][1010];

int main() {
  string s, t;
  cin >> s >> t;
  int n = s.size();
  int m = t.size();

  rep(i, 1010) rep(j, 1010) dp[i][j] = INF;
  dp[0][0] = 0;

  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      if (i > 0) chmin(dp[i][j], dp[i - 1][j] + 1);
      if (j > 0) chmin(dp[i][j], dp[i][j - 1] + 1);

      if (i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1])
          chmin(dp[i][j], dp[i - 1][j - 1]);
        else
          chmin(dp[i][j], dp[i - 1][j - 1] + 1);
      }
    }
  }

  cout << dp[n][m] << endl;
  return 0;
}