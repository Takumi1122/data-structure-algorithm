#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 円周 最大値DP 累積和

/*
    参考リンク
    ABC 95 D - Static Sushi
      https://atcoder.jp/contests/abc095/tasks/arc096_b
*/

int main() {
  ll n, c;
  cin >> n >> c;
  // 1 < x1 < x2 < ... < xn < c
  vector<ll> x(n), v(n);
  rep(i, n) cin >> x[i] >> v[i];

  vector<ll> suml(n + 1), sumr(n + 1);
  // 時計回り
  rep(i, n) suml[i + 1] = suml[i] + v[i];
  // 反時計回り
  rep(i, n) sumr[i + 1] = sumr[i] + v[n - 1 - i];

  // dp1[i+1]: 時計回りでi個目までの寿司を対象とするときのカロリー摂取量の最大
  // dp2[i+1]: 反時計回りでi個目までの寿司を対象とするときのカロリー摂取量の最大
  vector<ll> dp1(n + 1), dp2(n + 1);
  rep(i, n) {
    dp1[i + 1] = max(dp1[i], suml[i] + v[i] - x[i]);
    dp2[i + 1] = max(dp2[i], sumr[i] + v[n - 1 - i] - (c - x[n - i - 1]));
  }

  ll ans = 0;
  rep(i, n + 1) {
    ans = max(ans, dp1[i] + dp2[n - i] - (i == 0 ? 0 : x[i - 1]));
    ans = max(ans, dp1[i] + dp2[n - i] - (i == n ? 0 : (c - x[i])));
  }

  cout << ans << endl;
  return 0;
}