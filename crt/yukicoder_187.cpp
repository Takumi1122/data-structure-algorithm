#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    yukicoder 0187 中華風 (Hard)
      https://yukicoder.me/problems/no/187
*/

const ll MOD = 1000000007;

// 最大公約数
ll gcd(ll a, ll b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

// Garner のアルゴリズムの前処理
ll preGarner(vector<ll> &b, vector<ll> &m, ll MOD) {
  ll res = 1;
  for (int i = 0; i < (int)b.size(); ++i) {
    for (int j = 0; j < i; ++j) {
      ll g = gcd(m[i], m[j]);

      // これを満たさなければ解はない
      if ((b[i] - b[j]) % g != 0) return -1;

      // s = m[i], t = m[j] を仮想的に素因数分解して
      // s = p^k ... q^l ..., t = q^m ... r^n ... となったときに

      // p については i の方が大きかったものについての j との差分、と q
      m[i] /= g;
      // p については j の方が大きかったものについての i との差分、と r
      m[j] /= g;

      /*
          残る g を i と j に振り分ける
          (i の方が指数大きかった素因子 p の分は最終的に gi に、
           j の方が指数大きかった素因子 p の分は最終的に gj に)
      */
      // ひとまず j 側にある p については gj のみに行くようにする
      ll gi = gcd(m[i], g), gj = g / gi;

      // 本来 i 側に行くべき p で gj 側にあるものを gi 側に寄せていく
      do {
        g = gcd(gi, gj);
        gi *= g, gj /= g;
      } while (g != 1);

      // i 側と j 側に戻していく
      m[i] *= gi, m[j] *= gj;

      // m[i] と m[j] が元より小さくなったのに合わせて余りも計算し直しておく
      b[i] %= m[i], b[j] %= m[j];
    }
  }
  for (int i = 0; i < (int)b.size(); ++i) (res *= m[i]) %= MOD;
  return res;
}

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
ll modinv(ll a, ll m) {
  ll x, y;
  extGCD(a, m, x, y);
  return mod(x, m);  // 気持ち的には x % m だが、x が負かもしれないので
}

// Garner のアルゴリズム, x%MOD, LCM%MOD を求める
// (mは互いに素でなければならない)
ll Garner(vector<ll> b, vector<ll> m, ll MOD) {
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

int main() {
  int n;
  cin >> n;
  vector<ll> b(n), m(n);
  bool exist_non_zero = false;
  rep(i, n) {
    cin >> b[i] >> m[i];
    if (b[i]) exist_non_zero = true;
  }
  ll lcm = preGarner(b, m, MOD);

  if (!exist_non_zero)
    cout << lcm << endl;
  else if (lcm == -1)
    cout << -1 << endl;
  else
    cout << Garner(b, m, MOD) << endl;
}