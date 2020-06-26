#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 分割数

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
  mint inv() const { return pow(mod - 2); }
  mint& operator/=(const mint a) { return (*this) *= a.inv(); }
  mint operator/(const mint a) const {
    mint res(*this);
    return res /= a;
  }
};

template <class T>
struct Partition {
  vector<vector<T> > P;
  constexpr Partition(int MAX) noexcept : P(MAX, vector<T>(MAX, 0)) {
    for (int k = 0; k < MAX; ++k) P[0][k] = 1;
    for (int n = 1; n < MAX; ++n) {
      for (int k = 1; k < MAX; ++k) {
        P[n][k] = P[n][k - 1] + (n - k >= 0 ? P[n - k][k] : 0);
      }
    }
  }
  constexpr T get(int n, int k) {
    if (n < 0 || k < 0) return 0;
    return P[n][k];
  }
};

int main() {
  Partition<mint> pt(5100);
  int n, k;
  cin >> n >> k;
  cout << pt.get(n, k).x << endl;
}