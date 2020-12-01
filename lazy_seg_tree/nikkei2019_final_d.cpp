#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    全国統一プログラミング王決定戦本戦 D - Deforestation
      https://atcoder.jp/contests/nikkei2019-final/tasks/nikkei2019_final_d
*/

template <class Monoid, class Action>
struct SegTree {
  using FuncMonoid = function<Monoid(Monoid, Monoid)>;
  using FuncAction = function<void(Monoid &, Action)>;
  using FuncLazy = function<void(Action &, Action)>;
  FuncMonoid FM;
  FuncAction FA;
  FuncLazy FL;
  Monoid UNITY_MONOID;
  Action UNITY_LAZY;
  int SIZE, HEIGHT;
  vector<Monoid> dat;
  vector<Action> lazy;

  SegTree() {}
  SegTree(int n, const FuncMonoid fm, const FuncAction fa, const FuncLazy fl,
          const Monoid &unity_monoid, const Action &unity_lazy)
      : FM(fm),
        FA(fa),
        FL(fl),
        UNITY_MONOID(unity_monoid),
        UNITY_LAZY(unity_lazy) {
    SIZE = 1;
    HEIGHT = 0;
    while (SIZE < n) SIZE <<= 1, ++HEIGHT;
    dat.assign(SIZE * 2, UNITY_MONOID);
    lazy.assign(SIZE * 2, UNITY_LAZY);
  }
  void init(int n, const FuncMonoid fm, const FuncAction fa, const FuncLazy fl,
            const Monoid &unity_monoid, const Action &unity_lazy) {
    FM = fm;
    FA = fa;
    FL = fl;
    UNITY_MONOID = unity_monoid;
    UNITY_LAZY = unity_lazy;
    SIZE = 1;
    HEIGHT = 0;
    while (SIZE < n) SIZE <<= 1, ++HEIGHT;
    dat.assign(SIZE * 2, UNITY_MONOID);
    lazy.assign(SIZE * 2, UNITY_LAZY);
  }

  /* set, a is 0-indexed */
  void set(int a, const Monoid &v) { dat[a + SIZE] = v; }
  void build() {
    for (int k = SIZE - 1; k > 0; --k) dat[k] = FM(dat[k * 2], dat[k * 2 + 1]);
  }

  /* update [a, b) */
  inline void evaluate(int k) {
    if (lazy[k] == UNITY_LAZY) return;
    if (k < SIZE) FL(lazy[k * 2], lazy[k]), FL(lazy[k * 2 + 1], lazy[k]);
    FA(dat[k], lazy[k]);
    lazy[k] = UNITY_LAZY;
  }
  inline void update(int a, int b, const Action &v, int k, int l, int r) {
    evaluate(k);
    if (a <= l && r <= b)
      FL(lazy[k], v), evaluate(k);
    else if (a < r && l < b) {
      update(a, b, v, k * 2, l, (l + r) >> 1),
          update(a, b, v, k * 2 + 1, (l + r) >> 1, r);
      dat[k] = FM(dat[k * 2], dat[k * 2 + 1]);
    }
  }
  inline void update(int a, int b, const Action &v) {
    update(a, b, v, 1, 0, SIZE);
  }

  /* get [a, b) */
  inline Monoid get(int a, int b, int k, int l, int r) {
    evaluate(k);
    if (a <= l && r <= b)
      return dat[k];
    else if (a < r && l < b)
      return FM(get(a, b, k * 2, l, (l + r) >> 1),
                get(a, b, k * 2 + 1, (l + r) >> 1, r));
    else
      return UNITY_MONOID;
  }
  inline Monoid get(int a, int b) { return get(a, b, 1, 0, SIZE); }
  inline Monoid operator[](int a) { return get(a, a + 1); }

  /* debug */
  void print() {
    for (int i = 0; i < SIZE; ++i) {
      cout << (*this)[i];
      if (i != SIZE) cout << ",";
    }
    cout << endl;
  }
};

int main() {
  int n, m;
  cin >> n >> m;

  // 更新(l, r, v): 区間[l, r)の値をvと比べて大きい方に更新する
  // 取得i: iの値を取得する
  auto fm = [](ll a, ll b) { return max(a, b); };
  auto fa = [](ll &a, ll d) { a = max(a, d); };
  auto fl = [](ll &d, ll e) { d = max(d, e); };
  SegTree<ll, ll> seg(n + 1, fm, fa, fl, 0, 0);

  rep(i, m) {
    ll t;
    int l, r;
    cin >> t >> l >> r;
    --l;
    seg.update(l, r, t);
  }

  ll ans = 0;
  rep(i, n) ans += seg.get(i, i + 1);

  cout << ans << endl;
  return 0;
}