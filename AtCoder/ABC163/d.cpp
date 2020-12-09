#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 数列の和

/*
    参考リンク
    ABC 163 D - Sum of Large Numbers
      https://atcoder.jp/contests/abc163/tasks/abc163_d
*/

const int mod = 1000000007;
int main() {
  ll n, k;
  cin >> n >> k;

  ll ans = 0;
  for (ll i = k; i <= n + 1; ++i) {
    ll first = i * (i - 1) / 2;
    ll final = (n * 2 - i + 1) * i / 2;
    ll add = final - first + 1;
    ans = (ans + add) % mod;
  }
  cout << ans << endl;
  return 0;
}