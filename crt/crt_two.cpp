#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    // 中国剰余定理(2元の場合)
    m1とm2を互いに素な正の整数とする

      x ≡ b1 (mod m1)
      x ≡ b2 (mod m2)

    を満たす整数xが0以上m1m2未満にただ1つ存在する

    特にそれをrとすると

      x ≡ r (mod m1*m2)

    が成立する
*/

// 負の数にも対応した mod
// 例えば -17 を 5 で割った余りは本当は 3 (-17 ≡ 3 (mod. 5))
// しかし単に -17 % 5 では -2 になってしまう
inline ll mod(ll a, ll m) { return (a % m + m) % m; }

// 拡張 Euclid の互除法
// ap + bq = gcd(a, b) となる (p, q) を求め、d = gcd(a, b) をリターンします
ll extGcd(ll a, ll b, ll &p, ll &q) {
  if (b == 0) {
    p = 1;
    q = 0;
    return a;
  }
  ll d = extGcd(b, a % b, q, p);
  q -= a / b * p;
  return d;
}

// 中国剰余定理
// リターン値を (r, m) とすると解は x ≡ r (mod. m)
// 解なしの場合は (0, -1) をリターン
pair<ll, ll> chineseRem(ll b1, ll m1, ll b2, ll m2) {
  ll p, q;
  ll d = extGcd(m1, m2, p, q);  // p is inv of m1/d (mod. m2/d)
  // 解の必要十分条件: b1 ≡ b2 (mod gcd(m1, m2))
  if ((b2 - b1) % d != 0) return make_pair(0, -1);
  ll m = m1 * (m2 / d);  // lcm of (m1, m2)
  ll tmp = (b2 - b1) / d * p % (m2 / d);
  ll r = mod(b1 + m1 * tmp, m);
  return make_pair(r, m);
}

// x ≡ 2 (mod 3)
// x ≡ 3 (mod 5)
int main() {
  pair<ll, ll> res = chineseRem(2, 3, 3, 5);
  cout << "x ≡ " << res.first << " (mod. " << res.second << ")" << endl;
}