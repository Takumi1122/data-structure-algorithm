#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// ナップサック DP を in-place 化
// メモリを節約

/*
    in-place化の条件
    ・左から順にシーケンシャルに見ていくようなDP
    ・dp[i][j] から dp[i+1][k] への遷移において、常に k > jとなっているとき
*/

/*
    参考リンク
    Educational DP Contest D - Knapsack 1
      https://atcoder.jp/contests/dp/tasks/dp_d

    LIS でも大活躍！ DP の配列使いまわしテクニックを特集
      https://qiita.com/drken/items/68b8503ad4ffb469624c
*/

template <class T>
void chmax(T &a, T b) {
  if (a < b) a = b;
}

int main() {
  int n, W;
  cin >> n >> W;
  vector<ll> weight(n), value(n);
  rep(i, n) cin >> weight[i] >> value[i];

  vector<ll> dp(W + 1, 0);
  for (int i = 0; i < n; ++i) {
    for (int w = W; w >= 0; --w) {
      if (w - weight[i] >= 0) {
        chmax(dp[w], dp[w - weight[i]] + value[i]);
      }
    }
  }
  cout << dp[W] << endl;
}