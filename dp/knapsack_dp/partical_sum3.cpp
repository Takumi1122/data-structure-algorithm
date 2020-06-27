#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// o(n * A) 最小個数部分和問題

const int INF =
    1 << 29;  // 十分大きい値にする, INT_MAX にしないのはオーバーフロー対策

// 入力
int n, A;
int a[110];

// DPテーブル
int dp[110][10010];

int main() {
  cin >> n >> A;
  rep(i, n) cin >> a[i];

  // 一旦すべて INF に
  rep(i, 110) rep(j, 10010) dp[i][j] = INF;
  dp[0][0] = 0;  // dp[0][0] だけ 0 に

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= A; ++j) {
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
      if (j >= a[i]) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j - a[i]] + 1);
    }
  }

  if (dp[n][A] < INF)
    cout << dp[n][A] << endl;
  else
    cout << -1 << endl;
}