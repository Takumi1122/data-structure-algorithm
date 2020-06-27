#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// o(|s| * |t|) 最長共通部分列(LCS)問題

const int INF = 1 << 29;  // 十分大きい値にする

// 入力
string s, t;

// DP テーブル
int dp[1010][1010];

int main() {
  cin >> s >> t;

  memset(dp, 0, sizeof(dp));  // 初期化
  for (int i = 0; i < s.size(); ++i) {
    for (int j = 0; j < t.size(); ++j) {
      if (s[i] == t[j]) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
      dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i + 1][j]);
      dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j + 1]);
    }
  }

  cout << dp[s.size()][t.size()] << endl;
}