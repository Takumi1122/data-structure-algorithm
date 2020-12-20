#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

#include <atcoder/all>
using namespace atcoder;

// s+kx ≡ 0 (mod n) <=> kx ≡ -s (mod n)
/*
    kとnが互いに素ならば x ≡ (k^-1)*(-s) (mod n) 逆元

    kとnが互いに素ではない時(gはnとkの最大公約数)
    s+kx = ny
    s = ny -kx
    // sはgの倍数でなければならない
    s = g(n'y - k'x)
*/

/*
    参考リンク
    ABC 186 E - Throne
      https://atcoder.jp/contests/abc186/tasks/abc186_e
*/

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll solve() {
  ll n, s, k;
  cin >> n >> s >> k;
  ll g = gcd(n, k);
  if (s % g) return -1;
  n /= g, s /= g, k /= g;
  // 動的にmodをとる
  modint::set_mod(n);
  modint ans = -modint(s) / k;
  return ans.val();
}

int main() {
  int t;
  cin >> t;
  rep(i, t) cout << solve() << endl;
}