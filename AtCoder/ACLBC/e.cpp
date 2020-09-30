#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// Segment Tree
template <class Monoid, class Action>
struct SegTree {
  using FuncMonoid = function<Monoid(Monoid, Monoid)>;
  using FuncAction = function<void(Monoid&, Action)>;
  using FuncLazy = function<void(Action&, Action)>;
  FuncMonoid FM;
  FuncAction FA;
  FuncLazy FL;
  Monoid IDENTITY_MONOID;
  Action IDENTITY_LAZY;
  int SIZE, HEIGHT;
  vector<Monoid> dat;
  vector<Action> lazy;

  SegTree() {}
  SegTree(int n, const FuncMonoid fm, const FuncAction fa, const FuncLazy fl,
          const Monoid& identity_monoid, const Action& identity_lazy)
      : FM(fm),
        FA(fa),
        FL(fl),
        IDENTITY_MONOID(identity_monoid),
        IDENTITY_LAZY(identity_lazy) {
    SIZE = 1, HEIGHT = 0;
    while (SIZE < n) SIZE <<= 1, ++HEIGHT;
    dat.assign(SIZE * 2, IDENTITY_MONOID);
    lazy.assign(SIZE * 2, IDENTITY_LAZY);
  }
  void init(int n, const FuncMonoid fm, const FuncAction fa, const FuncLazy fl,
            const Monoid& identity_monoid, const Action& identity_lazy) {
    FM = fm, FA = fa, FL = fl;
    IDENTITY_MONOID = identity_monoid, IDENTITY_LAZY = identity_lazy;
    SIZE = 1;
    HEIGHT = 0;
    while (SIZE < n) SIZE <<= 1, ++HEIGHT;
    dat.assign(SIZE * 2, IDENTITY_MONOID);
    lazy.assign(SIZE * 2, IDENTITY_LAZY);
  }

  // set, a is 0-indexed
  void set(int a, const Monoid& v) { dat[a + SIZE] = v; }
  void build() {
    for (int k = SIZE - 1; k > 0; --k) dat[k] = FM(dat[k * 2], dat[k * 2 + 1]);
  }

  // update [a, b)
  inline void evaluate(int k) {
    if (lazy[k] == IDENTITY_LAZY) return;
    if (k < SIZE) FL(lazy[k * 2], lazy[k]), FL(lazy[k * 2 + 1], lazy[k]);
    FA(dat[k], lazy[k]);
    lazy[k] = IDENTITY_LAZY;
  }
  inline void update(int a, int b, const Action& v, int k, int l, int r) {
    evaluate(k);
    if (a <= l && r <= b)
      FL(lazy[k], v), evaluate(k);
    else if (a < r && l < b) {
      update(a, b, v, k * 2, l, (l + r) >> 1);
      update(a, b, v, k * 2 + 1, (l + r) >> 1, r);
      dat[k] = FM(dat[k * 2], dat[k * 2 + 1]);
    }
  }
  inline void update(int a, int b, const Action& v) {
    update(a, b, v, 1, 0, SIZE);
  }

  // get [a, b)
  inline Monoid get(int a, int b, int k, int l, int r) {
    evaluate(k);
    if (a <= l && r <= b)
      return dat[k];
    else if (a < r && l < b)
      return FM(get(a, b, k * 2, l, (l + r) >> 1),
                get(a, b, k * 2 + 1, (l + r) >> 1, r));
    else
      return IDENTITY_MONOID;
  }
  inline Monoid get(int a, int b) { return get(a, b, 1, 0, SIZE); }
  inline Monoid operator[](int a) { return get(a, a + 1); }

  // debug
  void print() {
    for (int i = 0; i < SIZE; ++i) {
      if (i) cout << ",";
      cout << (*this)[i];
    }
    cout << endl;
  }
};

// modint
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

using pll = pair<mint, int>;  // val, num

int main() {
  int n, q;
  cin >> n >> q;
  vector<mint> ten(n, 1), sum(n + 1, 0);

  // ten[i] = 10^i
  for (int i = 1; i < n; ++i) ten[i] = ten[i - 1] * 10;
  // sum[1] = sum[0] + ten[0] = 1
  // sum[2] = sum[1] + ten[1] = 11
  // sum[3] = sum[2] + ten[2] = 111
  for (int i = 0; i < n; ++i) sum[i + 1] = sum[i] + ten[i];

  // define segtree
  auto fm = [&](pll a, pll b) {
    mint first = a.first * ten[b.second] + b.first;
    int second = a.second + b.second;
    return pll(first, second);
  };
  auto fa = [&](pll& a, int d) {
    if (d == 0) return;
    a.first = sum[a.second] * d;
  };
  auto fl = [&](int& d, int e) { d = e; };
  SegTree<pll, int> seg(n, fm, fa, fl, pll(mint(0), 0), 0);

  // initialization
  for (int i = 0; i < n; ++i) seg.set(i, pll(mint(1), 1));
  seg.build();

  // query
  rep(i, q) {
    int l, r, d;
    cin >> l >> r >> d;
    --l;
    seg.update(l, r, d);
    cout << seg.get(0, n).first.x << endl;
  }
}