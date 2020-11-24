#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    Educational DP Contest C - Vacation
      https://atcoder.jp/contests/dp/tasks/dp_c
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

ll a[100010][3];
ll dp[100010][3];

int main() {
  int n;
  cin >> n;
  rep(i, n) rep(j, 3) cin >> a[i][j];

  rep(i, n) rep(j, 3) rep(k, 3) {
    if (j == k) continue;
    chmax(dp[i + 1][k], dp[i][j] + a[i][k]);
  }

  ll ans = 0;
  rep(j, 3) chmax(ans, dp[n][j]);
  cout << ans << endl;
}