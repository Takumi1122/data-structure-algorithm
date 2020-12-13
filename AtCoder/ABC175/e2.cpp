#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 175 E - Picking Goods
      https://atcoder.jp/contests/abc175/tasks/abc175_e
*/

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

ll v[3100][3100], dp[3100][3100][5];
int main() {
  int r, c, K;
  cin >> r >> c >> K;
  rep(i, K) {
    ll r, c, t;
    cin >> r >> c >> t;
    v[r][c] = t;
  }

  for (int i = 0; i <= r; ++i) {
    for (int j = 0; j <= c; ++j) {
      for (int k = 0; k <= 3; ++k) {
        // 上へ行く
        if (i - 1 >= 0) {
          chmax(dp[i][j][0], dp[i - 1][j][k]);
          chmax(dp[i][j][1], dp[i - 1][j][k] + v[i][j]);
        }

        // 右へ行く
        if (j - 1 >= 0) {
          chmax(dp[i][j][k], dp[i][j - 1][k]);
          if (k - 1 >= 0) chmax(dp[i][j][k], dp[i][j - 1][k - 1] + v[i][j]);
        }
      }
    }
  }

  ll ans = 0;
  for (int k = 0; k <= 3; ++k) chmax(ans, dp[r][c][k]);
  cout << ans << endl;
  return 0;
}