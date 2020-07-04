#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 個数制限なしナップサック問題

// DPテーブル
const int MAX_N = 110;
const int MAX_W = 110000;
int dp[MAX_N][MAX_W];

int main() {
  int n, W;
  cin >> n >> W;
  vector<int> weight(n), value(n);
  rep(i, n) cin >> weight[i] >> value[i];

  // DP初期条件: dp[i][0] = 0
  rep(i, MAX_N) rep(w, MAX_W) dp[i][w] = 1 << 29;  // INF
  for (int i = 0; i <= n; ++i) dp[i][0] = 0;

  // DPループ
  for (int i = 0; i < n; ++i) {
    for (int w = 0; w <= W; ++w) {
      dp[i + 1][w] = min(dp[i + 1][w], dp[i][w]);
      if (w >= weight[i])
        dp[i + 1][w] = min(dp[i + 1][w], dp[i + 1][w - weight[i]] + value[i]);
    }
  }

  cout << dp[n][W] << endl;
}