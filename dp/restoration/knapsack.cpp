#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 入力
int n, W;
int weight[110], value[110];

// DPテーブル
int dp[110][10010] = {0};  // テーブルの初期値はすべて 0 にしておきます

// 復元用テーブル
int prev_w[110][10010];

int main() {
  // 入力受け取り
  cin >> n >> W;
  rep(i, n) cin >> value[i] >> weight[i];

  // DPループ
  for (int i = 0; i < n; ++i) {
    for (int w = 0; w <= W; ++w) {
      // i 番目の品物を選ぶ場合を考える
      if (w >= weight[i]) {
        if (dp[i + 1][w] < dp[i][w - weight[i]] + value[i]) {
          dp[i + 1][w] = dp[i][w - weight[i]] + value[i];
          prev_w[i + 1][w] = w - weight[i];
        }
      }

      // i 番目の品物を選ばない場合を考える
      if (dp[i + 1][w] < dp[i][w]) {
        dp[i + 1][w] = dp[i][w];
        prev_w[i + 1][w] = w;
      }
    }
  }

  // 最適値の出力
  cout << dp[n][W] << endl;

  // 復元
  cout << "Selected items are..." << endl;
  int cur_w = W;
  for (int i = n - 1; i >= 0; --i) {
    // 選んでいた場合
    if (prev_w[i + 1][cur_w] == cur_w - weight[i]) {
      cout << i << " th item (weight = " << weight[i]
           << ", value = " << value[i] << ")" << endl;
    }

    // 復元テーブルをたどる
    cur_w = prev_w[i + 1][cur_w];
  }
}