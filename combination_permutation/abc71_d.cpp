#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 1*2 or 2*1のドミノの色塗り

/*
    参考リンク
    ABC 71 D - Coloring Dominoes
      https://atcoder.jp/contests/abc071/tasks/arc081_b
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

int main() {
  int n;
  cin >> n;
  vector<string> s(2);
  cin >> s[0] >> s[1];

  mint ans = 1;
  int x = 0;
  int pre = -1;
  while (x < n) {
    if (s[0][x] == s[1][x]) {
      if (pre < 0) {
        ans = 3;
      } else if (pre == 0) {
        ans *= 2;
      } else {
        ans *= 1;
      }
      x++;
      pre = 0;
    } else {
      if (pre < 0) {
        ans = 6;
      } else if (pre == 0) {
        ans *= 2;
      } else {
        ans *= 3;
      }
      x += 2;
      pre = 1;
    }
  }

  cout << ans.x << endl;
  return 0;
}