#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 128 E - Roadwork
      https://atcoder.jp/contests/abc128/tasks/abc128_e
*/

// Segment Tree
template <class Monoid, class Action>
struct SegTree {
  using FuncMonoid = function<Monoid(Monoid, Monoid)>;
  using FuncAction = function<void(Monoid&, Action)>;
  using FuncComposition = function<void(Action&, Action)>;
  FuncMonoid FM;
  FuncAction FA;
  FuncComposition FC;
  Monoid IDENTITY_MONOID;
  Action IDENTITY_LAZY;
  int SIZE, HEIGHT;
  vector<Monoid> dat;
  vector<Action> lazy;

  SegTree() {}
  SegTree(int n, const FuncMonoid fm, const FuncAction fa,
          const FuncComposition fc, const Monoid& identity_monoid,
          const Action& identity_lazy)
      : FM(fm),
        FA(fa),
        FC(fc),
        IDENTITY_MONOID(identity_monoid),
        IDENTITY_LAZY(identity_lazy) {
    SIZE = 1, HEIGHT = 0;
    while (SIZE < n) SIZE <<= 1, ++HEIGHT;
    dat.assign(SIZE * 2, IDENTITY_MONOID);
    lazy.assign(SIZE * 2, IDENTITY_LAZY);
  }

  void init(int n, const FuncMonoid fm, const FuncAction fa,
            const FuncComposition fc, const Monoid& identity_monoid,
            const Action& identity_lazy) {
    FM = fm, FA = fa, FC = fc;
    IDENTITY_MONOID = identity_monoid, IDENTITY_LAZY = identity_lazy;
    SIZE = 1, HEIGHT = 0;
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
    if (k < SIZE) FC(lazy[k * 2], lazy[k]), FC(lazy[k * 2 + 1], lazy[k]);
    FA(dat[k], lazy[k]);
    lazy[k] = IDENTITY_LAZY;
  }
  inline void update(int a, int b, const Action& v, int k, int l, int r) {
    evaluate(k);
    if (a <= l && r <= b)
      FC(lazy[k], v), evaluate(k);
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
      cout << get(i, i + 1);
    }
    cout << endl;
  }
};

const ll INF = 1LL << 50;

int main() {
  int n, q;
  cin >> n >> q;
  vector<ll> s(n), t(n), x(n);
  rep(i, n) cin >> s[i] >> t[i] >> x[i];
  vector<ll> d(q);
  rep(i, q) cin >> d[i];

  auto fm = [](ll a, ll b) { return min(a, b); };
  auto fa = [](ll& a, ll d) { a = min(a, d); };
  auto fc = [](ll& d, ll e) { d = min(d, e); };
  SegTree<ll, ll> seg(q, fm, fa, fc, INF, INF);

  rep(i, n) {
    int l = lower_bound(d.begin(), d.end(), s[i] - x[i]) - d.begin();
    int r = lower_bound(d.begin(), d.end(), t[i] - x[i]) - d.begin();
    seg.update(l, r, x[i]);
  }

  rep(i, q) {
    ll s = seg.get(i, i + 1);
    if (s < INF) {
      cout << s << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}