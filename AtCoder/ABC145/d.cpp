#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

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

// 階乗を求める
mint factorial(int k) {
  mint sum = 1;
  int cnt = 0;
  mint i = 1;
  while (cnt < k) {
    sum *= i;
    cnt += 1;
    i += 1;
  }
  return sum;
}

int main() {
  int x, y;
  cin >> x >> y;

  if ((x + y) % 3 != 0) {
    cout << 0 << endl;
    return 0;
  }

  if (x * 2 < y || y * 2 < x) {
    cout << 0 << endl;
    return 0;
  }

  if (x * 2 == y || y * 2 == x) {
    cout << 1 << endl;
    return 0;
  }

  if (x == y) {
    int a0 = (x + y) / 3;
    mint a1 = factorial(a0);
    mint a2 = factorial(a0 / 2);
    mint ans = a1 / (a2 * a2);
    cout << ans.x << endl;
    return 0;
  }

  int sub = abs(x - y);
  int b0 = (x + y) / 3;
  int b1 = (b0 + sub) / 2;
  mint b2 = factorial(b0);
  mint b3 = factorial(b1);
  mint b4 = factorial(b0 - b1);
  mint ans = b2 / (b3 * b4);
  cout << ans.x << endl;

  return 0;
}