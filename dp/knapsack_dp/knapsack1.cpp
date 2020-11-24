#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// O(n * W) ナップサック問題

/*
    参考リンク
    Educational DP Contest D - Knapsack 1
      https://atcoder.jp/contests/dp/tasks/dp_d
*/

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

ll weight[110], value[110];
ll dp[110][100100];

int main() {
  int n, W;
  cin >> n >> W;
  rep(i, n) cin >> weight[i] >> value[i];

  for (int i = 0; i < n; ++i) {
    for (int w = 0; w <= W; ++w) {
      if (w - weight[i] >= 0) {
        chmax(dp[i + 1][w], dp[i][w - weight[i]] + value[i]);
      }
      chmax(dp[i + 1][w], dp[i][w]);
    }
  }

  cout << dp[n][W] << endl;
  return 0;
}