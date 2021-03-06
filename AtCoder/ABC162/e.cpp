#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 162 E - Sum of gcd of Tuples (Hard)
      https://atcoder.jp/contests/abc162/tasks/abc162_e
*/

const int mod = 1000000007;
struct mint {
  ll x;  // typedef long long ll;
  mint(ll x = 0) : x((x % mod + mod) % mod) {}
  mint operator-() const { return mint(-x); }
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod - a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const { return mint(*this) += a; }
  mint operator-(const mint a) const { return mint(*this) -= a; }
  mint operator*(const mint a) const { return mint(*this) *= a; }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod - 2); }
  mint& operator/=(const mint a) { return *this *= a.inv(); }
  mint operator/(const mint a) const { return mint(*this) /= a; }
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }

int main() {
  int n, k;
  cin >> n >> k;

  mint ans;
  // d[i]: gcd(A) = iとなる個数
  vector<mint> d(k + 1);
  for (int i = k; i >= 1; --i) {
    // gcd(A) = iの倍数となる個数を計算
    d[i] = mint(k / i).pow(n);
    for (int j = i * 2; j <= k; j += i) {
      // iの倍数であり,i自身ではない個数を引く
      d[i] -= d[j];
    }
  }

  for (int i = 1; i <= k; ++i) ans += d[i] * i;

  cout << ans.x << endl;
  return 0;
}
