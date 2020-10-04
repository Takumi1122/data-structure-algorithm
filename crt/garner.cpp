#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 負の数にも対応した mod (a = -11 とかでも OK)
inline ll mod(ll a, ll m) {
  ll res = a % m;
  if (res < 0) res += m;
  return res;
}

// 拡張 Euclid の互除法
ll extGCD(ll a, ll b, ll &p, ll &q) {
  if (b == 0) {
    p = 1;
    q = 0;
    return a;
  }
  ll d = extGCD(b, a % b, q, p);
  q -= a / b * p;
  return d;
}

// 逆元計算 (ここでは a と m が互いに素であることが必要)
// モジュラ逆数
ll modinv(ll a, ll m) {
  ll x, y;
  extGCD(a, m, x, y);
  return mod(x, m);  // 気持ち的には x % m だが、x が負かもしれないので
}

// x % m[i] = b[i] % m[i] を満たす正で最小の x を返す
// i!=j に対して gcd(m[i], m[j])=1 であると仮定
// O(nlog(m[i]))
ll garner(vector<ll> b, vector<ll> m) {
  int n = b.size();
  ll m_prod = 1;       // m_prod には m[i] の積を入れていく
  ll x = b[0] % m[0];  // 最初の条件を満たすような x の初期値
  for (int i = 1; i < n; i++) {
    m_prod *= m[i - 1];  // m の累積積を更新
    ll t = ((b[i] - x) * modinv(m_prod, m[i])) % m[i];
    if (t < 0) t += m[i];  // 負の数の剰余の対策
    x += t * m_prod;       // x を更新
  }
  return x;
}