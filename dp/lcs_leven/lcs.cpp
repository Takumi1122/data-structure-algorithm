#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// o(|s| * |t|) 最長共通部分列(LCS)問題

const int INF = 1 << 29;
int dp[1010][1010];

int main() {
  string s, t;
  cin >> s >> t;
  int n = s.size();
  int m = t.size();

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i] == t[j]) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
      dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i + 1][j]);
      dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j + 1]);
    }
  }

  cout << dp[n][m] << endl;
  return 0;
}