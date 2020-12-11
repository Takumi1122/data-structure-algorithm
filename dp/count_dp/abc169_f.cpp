#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

//　数え上げ 部分集合の部分集合

/*
    参考リンク
    ABC 169 F - Knapsack for All Subsets
      https://atcoder.jp/contests/abc169/tasks/abc169_f
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

  vector<vector<mint>> dp(n + 1, vector<mint>(s + 1));
  dp[0][0] = 1;

  rep(i, n) {
    rep(j, s + 1) {
      // AiがTに選ばれない,Uに選ばれない
      dp[i + 1][j] += dp[i][j] * 2;
      // AiがUに選ばれる
      if (j + a[i] <= s) dp[i + 1][j + a[i]] += dp[i][j];
    }
  }

  cout << dp[n][s] << endl;
  return 0;
}