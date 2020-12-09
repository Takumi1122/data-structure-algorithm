#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using pll = pair<ll, ll>;

// Aiが大きいものから順に,左詰め,または,右詰めしていく
// 「二択を繰り返す」というシチュエーション
// dp[i][j]:
// Aが大きい順にi+j個について,i個を左詰めして、j個を右詰めしたときのスコア

/*
    参考リンク
    ABC 163 E - Active Infants
      https://atcoder.jp/contests/abc163/tasks/abc163_e
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

int main() {
  int n;
  cin >> n;
  vector<pll> a(n);
  rep(i, n) cin >> a[i].first, a[i].second = i;
  sort(a.begin(), a.end(), greater<pll>());

  vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; i + j < n; ++j) {
      // left
      chmax(dp[i + 1][j], dp[i][j] + a[i + j].first * (a[i + j].second - i));

      // right
      chmax(dp[i][j + 1],
            dp[i][j] + a[i + j].first * ((n - 1 - j) - a[i + j].second));
    }
  }

  ll ans = 0;
  rep(i, n + 1) chmax(ans, dp[i][n - i]);
  cout << ans << endl;
  return 0;
}