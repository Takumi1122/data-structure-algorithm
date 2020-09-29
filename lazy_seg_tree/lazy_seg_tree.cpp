//
// segment tree (with lazy)
//
// verified:
//   AOJ Course Range Query - RMQ and RAQ
//     http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H&lang=jp
//
//   AtCoder ACL Beginner Contest E - Replace Digits
//     https://atcoder.jp/contests/abl/tasks/abl_e
//

/*
    セグメントツリーは「作用つきモノイド」上で定義される
      FM(a, b): 2 つのモノイド間に定義される演算
      FA(a, d): モノイド元 a への作用素 d による作用
      FC(d, e): 作用素 d への作用素 e の合成
      IDENTITY_MONOID: モノイドの単位元
      IDENTITY_LAZY: 作用素の単位元

    // Construction
    SegTree(N, fm, fa, fc, identity_monoid, identity_lazy)
      ex: starry sky tree (区間加算、区間min取得)
        auto fm = [](long long a, long long b) { return min(a, b); };
        auto fa = [](long long &a, long long d) { a += d; };
        auto fc = [](long long &d, long long e) { d += e; };
        SegTree<long long, long long> seg(N, fm, fa, fc, (1LL<<60), 0);

    // Initialization
    init(n): サイズ n に初期化
    set(a, v): a 番目の値を v にセットする
    build(): set した値を元にセグメントツリー全体を構築する、O(n)

    // Queries
    update(a, b, v): 区間 [a, b) を作用素 v を用いて更新する, O(log n)
    get(a, b): 区間 [a, b) についての演算結果を返す, O(log n)
*/

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

int main() {
  int n, q;
  cin >> n >> q;

  auto fm = [](ll a, ll b) { return min(a, b); };
  auto fa = [](ll& a, ll d) { a += d; };
  auto fc = [](ll& d, ll e) { d += e; };
  SegTree<ll, ll> seg(n, fm, fa, fc, (1LL << 60), 0);

  rep(i, n) seg.set(i, 0);
  seg.build();

  rep(i, q) {
    int query;
    cin >> query;
    if (query == 0) {
      int s, t, x;
      cin >> s >> t >> x;
      seg.update(s, t + 1, x);
    } else {
      int s, t;
      cin >> s >> t;
      cout << seg.get(s, t + 1) << endl;
    }
  }
  return 0;
}