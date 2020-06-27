#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// o(|s| * |t|) レーベンシュタイン距離 (diffコマンド)

const int INF = 1 << 29;  // 十分大きい値にする

// 入力
int n, m;
string s, t;

// DP テーブル
int dp[1010][1010];

int main() {
  cin >> n >> m >> s >> t;

  // 初期化
  rep(i, 1010) rep(j, 1010) dp[i][j] = INF;
  dp[0][0] = 0;

  for (int i = -1; i < (int)s.size(); ++i) {
    for (int j = -1; j < (int)t.size(); ++j) {
      if (i == -1 && j == -1) continue;  // dp[0][0] は考慮済
      if (i >= 0 && j >= 0) {
        if (s[i] == t[j])
          dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
        else
          dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + 1);
      }
      if (i >= 0) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j + 1] + 1);
      if (j >= 0) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i + 1][j] + 1);
    }
  }

  cout << dp[s.size()][t.size()] << endl;
}