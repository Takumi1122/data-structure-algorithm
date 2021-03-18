#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// A^x % 10 は周期4
// a^φ(m) ≡ 1 (mod m) aとmは互いに素
// φ(10) = 4

/*
    参考リンク
    ARC 113 B - A^B^C
      https://atcoder.jp/contests/arc113/tasks/arc113_b
*/

// a^n mod を計算する
ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main() {
  ll a, b, c;
  cin >> a >> b >> c;
  ll x = modpow(b, c, 4);
  x += 4;
  ll ans = modpow(a, x, 10);
  cout << ans << endl;
  return 0;
}