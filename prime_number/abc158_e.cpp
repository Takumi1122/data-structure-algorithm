#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 区間に関する問題において、累積和的なものを考える
// (al - ar) / 10^r
// 互いに素かどうか

/*
    参考リンク
    ABC158 E - Divisible Substring
      https://atcoder.jp/contests/abc158/tasks/abc158_e
*/

int main() {
  ll n, p;
  string s;
  cin >> n >> p >> s;

  // 素数2,5は10と互いに素ではない
  if (p == 2 || p == 5) {
    // 2の倍数: 下1桁が偶数であること
    // 5の倍数: 下1桁が0または5であること
    ll ans = 0;
    rep(i, n) if ((s[n - i - 1] - '0') % p == 0) ans += n - i;
    cout << ans << endl;
    return 0;
  }

  vector<ll> val(p, 0);
  ll tenfactor = 1;
  ll now = 0;
  val[now]++;
  // 文字列の右側からv個分からなる整数についてのmod
  rep(i, n) {
    now = (now + (s[n - i - 1] - '0') * tenfactor) % p;
    tenfactor = (tenfactor * 10) % p;
    val[now]++;
  }
  ll ans = 0;
  rep(i, p) ans += val[i] * (val[i] - 1) / 2;
  cout << ans << endl;
  return 0;
}