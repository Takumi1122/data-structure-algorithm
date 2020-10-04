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

/*
    // Garner のアルゴリズム  O(n^2)
    x%MOD, LCM%MOD を求める (mは互いに素でなければならない)

    for each step, we solve "coeffs[k] * t[k] +constants[k] = b[k] (mod. m[k])"
      coeffs[k] = m[0]m[1]...m[k-1]
      constants[k] = t[0] + t[1]m[0] + ... + t[k-1]m[0]m[1]...m[k-2]
*/
ll garner(vector<ll> b, vector<ll> m, ll MOD) {
  m.push_back(MOD);  // banpei
  vector<ll> coeffs((int)m.size(), 1);
  vector<ll> constants((int)m.size(), 0);
  for (int k = 0; k < (int)b.size(); ++k) {
    ll t = mod((b[k] - constants[k]) * modinv(coeffs[k], m[k]), m[k]);
    for (int i = k + 1; i < (int)m.size(); ++i) {
      (constants[i] += t * coeffs[i]) %= m[i];
      (coeffs[i] *= m[k]) %= m[i];
    }
  }
  return constants.back();
}