#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// O(n^2 * V) ナップサック問題

/*
    参考リンク
    Educational DP Contest E - Knapsack 2
      https://atcoder.jp/contests/dp/tasks/dp_e
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

const ll INF = 1LL << 60;

const int MAX_N = 110;
const int MAX_V = 100100;

ll weight[MAX_N], value[MAX_N];
ll dp[MAX_N][MAX_V];

int main() {
  ll n, W;
  cin >> n >> W;
  rep(i, n) cin >> weight[i] >> value[i];

  rep(i, MAX_N) rep(j, MAX_V) dp[i][j] = INF;
  dp[0][0] = 0;

  for (int i = 0; i < n; ++i) {
    for (int v = 0; v < MAX_V; ++v) {
      if (v - value[i] >= 0)
        chmin(dp[i + 1][v], dp[i][v - value[i]] + weight[i]);
      chmin(dp[i + 1][v], dp[i][v]);
    }
  }

  ll ans = 0;
  rep(v, MAX_V) {
    if (dp[n][v] <= W) ans = v;
  }
  cout << ans << endl;
}