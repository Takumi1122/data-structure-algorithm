#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 数え上げDP + bit全探索

/*
    参考リンク
    ABC 113 D - Number of Amidakuji
      https://atcoder.jp/contests/abc113/tasks/abc113_d
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

// num[j][k]:
// 1行の横線の引き方であって,j番目の縦線からk番目の縦線に移動する引き方の総数
ll num[8][8];
mint dp[101][8];

int main() {
  int h, w, k;
  cin >> h >> w >> k;

  rep(bit, 1 << (w - 1)) {
    bool ok = true;
    for (int i = 0; i < w - 2; i++) {
      if ((bit & (1 << i)) && (bit & (1 << (i + 1)))) ok = false;
    }
    if (!ok) continue;

    // p[j]: j番目の縦線からどこの縦線に移動するかを各jごとに計算する
    vector<int> p(w);
    rep(i, w) p[i] = i;
    rep(i, w - 1) {
      if (bit & (1 << i)) swap(p[i], p[i + 1]);
    }
    rep(i, w) num[i][p[i]]++;
  }

  dp[0][0] = 1;
  rep(i, h) rep(j, w) rep(k, w) dp[i + 1][k] += dp[i][j] * num[j][k];

  cout << dp[h][k - 1].x << endl;
  return 0;
}