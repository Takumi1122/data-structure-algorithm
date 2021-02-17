#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// dp[山札からとった枚数][後手かどうか]:
// その状態からスタートしたときの、最終的なカードの数値の差の最適値(先手なら最大値、後手なら最小値)

/*
    参考リンク
    ABC 78 D - ABS
      https://atcoder.jp/contests/abc078/tasks/arc085_b
*/

const ll INF = 1LL << 60;

int main() {
  ll n, z, w;
  cin >> n >> z >> w;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<vector<ll>> dp(n + 1, vector<ll>(2));
  for (int i = n - 1; i >= 0; --i) {
    // 先手番
    dp[i][0] = -INF;
    ll y = (i ? a[i - 1] : w);
    dp[i][0] = max(dp[i][0], abs(y - a[n - 1]));
    for (int j = i + 1; j < n; ++j) dp[i][0] = max(dp[i][0], dp[j][1]);

    // 後手番
    dp[i][1] = INF;
    ll x = (i ? a[i - 1] : z);
    dp[i][1] = min(dp[i][1], abs(x - a[n - 1]));
    for (int j = i + 1; j < n; ++j) dp[i][1] = min(dp[i][1], dp[j][0]);
  }

  cout << dp[0][0] << endl;
  return 0;
}