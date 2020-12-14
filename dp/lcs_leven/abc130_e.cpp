#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// ダブルカウントを防ぐ
// 共通部分列を数え上げる問題

/*
    参考リンク
    ABC 130 E - Common Subsequence
      https://atcoder.jp/contests/abc130/tasks/abc130_e
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
  mint operator+(const mint a) const {
    mint res(*this);
    return res += a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res -= a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res *= a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1) a *= *this;
    return a;
  }

  // for prime mod
  // フェルマーの小定理から a * a^(p-2) ≡ 1 (mod p) pは素数
  mint inv() const { return pow(mod - 2); }
  mint& operator/=(const mint a) { return (*this) *= a.inv(); }
  mint operator/(const mint a) const {
    mint res(*this);
    return res /= a;
  }
};

mint dp[2100][2100];

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> s(n);
  vector<int> t(m);
  rep(i, n) cin >> s[i];
  rep(i, m) cin >> t[i];

  dp[0][0] = 1;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      if (i - 1 >= 0 && j - 1 >= 0 && s[i - 1] == t[j - 1])
        dp[i][j] += dp[i - 1][j - 1];
      if (i - 1 >= 0) dp[i][j] += dp[i - 1][j];
      if (j - 1 >= 0) dp[i][j] += dp[i][j - 1];
      if (i - 1 >= 0 && j - 1 >= 0) dp[i][j] -= dp[i - 1][j - 1];
    }
  }
  cout << dp[n][m].x << endl;
  return 0;
}