#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 159 F - Knapsack for All Segments
      https://atcoder.jp/contests/abc159/tasks/abc159_f
*/

const int mod = 998244353;
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
  int n, s;
  cin >> n >> s;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  // q[i]: x^iについての係数
  vector<mint> q(s + 1);
  mint ans = 0;
  rep(i, n) {
    q[0] += 1;  // q += 1
    {           // q *= (1 + x^a[i])
      vector<mint> q2(s + 1);
      rep(j, s + 1) {
        q2[j] += q[j];
        if (j + a[i] <= s) q2[j + a[i]] += q[j];
      }
      q = q2;
    }
    ans += q[s];
  }
  cout << ans << endl;
  return 0;
}