#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

#include <atcoder/all>
using namespace atcoder;

using mint = modint998244353;

struct S {
  mint a;
  int size;
};

struct F {
  mint a, b;
};

S op(S l, S r) { return S{l.a + r.a, l.size + r.size}; }

S e() { return S{0, 0}; }

// sum(a + b) -> sum((a * x + y ) + (b * x + y)) -> sum((a + b) * x + 2 * y)
S mapping(F l, S r) { return S{r.a * l.a + r.size * l.b, r.size}; }

// sum(a + b) -> sum((a * x + y) + (b * x + y)) ->
// sum(((a * x + y ) * z + k) + ((b * x + y) * z + k)) ->
// sum((a + b) * z + 2(y * z + k))
F composition(F l, F r) { return F{r.a * l.a, r.b * l.a + l.b}; }

F id() { return F{1, 0}; }

int main() {
  int n, q;
  cin >> n >> q;

  vector<S> a(n);
  rep(i, n) {
    int x;
    cin >> x;
    a[i] = S{x, 1};
  }

  lazy_segtree<S, op, e, F, mapping, composition, id> seg(a);

  rep(i, q) {
    int t;
    cin >> t;
    if (t == 0) {
      int l, r;
      int c, d;
      cin >> l >> r >> c >> d;
      seg.apply(l, r, F{c, d});
    } else {
      int l, r;
      cin >> l >> r;
      cout << seg.prod(l, r).a.val() << endl;
    }
  }
}