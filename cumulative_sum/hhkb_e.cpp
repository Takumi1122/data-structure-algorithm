#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    HHKB E - Lamps
      https://atcoder.jp/contests/hhkb2020/tasks/hhkb2020_e
*/

// modint
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

int Left[2100][2100], Right[2100][2100], Up[2100][2100], Down[2100][2100];

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> fi(h);

  int k = 0;
  rep(i, h) {
    cin >> fi[i];
    rep(j, w) if (fi[i][j] == '.') k++;
  }

  // 前処理
  rep(i, h) {
    int cur = 0;
    rep(j, w) {
      if (fi[i][j] == '#')
        cur = 0;
      else
        ++cur;
      Left[i][j] = cur;
    }
  }

  rep(i, h) {
    int cur = 0;
    for (int j = w - 1; j >= 0; --j) {
      if (fi[i][j] == '#')
        cur = 0;
      else
        ++cur;
      Right[i][j] = cur;
    }
  }

  rep(j, w) {
    int cur = 0;
    rep(i, h) {
      if (fi[i][j] == '#')
        cur = 0;
      else
        ++cur;
      Up[i][j] = cur;
    }
  }

  rep(j, w) {
    int cur = 0;
    for (int i = h - 1; i >= 0; --i) {
      if (fi[i][j] == '#')
        cur = 0;
      else
        ++cur;
      Down[i][j] = cur;
    }
  }

  // 集計
  // 各通路マスに対して、それを照らすようなライト設置方法の個数を数え上げて、それを合算する
  mint res = 0;
  rep(i, h) {
    rep(j, w) {
      if (fi[i][j] == '#') continue;
      int num = Left[i][j] + Right[i][j] + Up[i][j] + Down[i][j] - 3;
      res += mint(2).pow(k) - mint(2).pow(k - num);
    }
  }
  cout << res.x << endl;
}