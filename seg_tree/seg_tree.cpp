#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 区間上の最小値 Range Minimam Query(RMQ)

template <class Monoid>
class SegTree {
  int n;                                       // 葉の数
  vector<Monoid> data;                         // データを格納するvector
  Monoid def;                                  // 初期値かつ単位元
  function<Monoid(Monoid, Monoid)> operation;  // 区間クエリで使う処理
  function<Monoid(Monoid, Monoid)> update;     // 点更新で使う処理

  // 区間[a,b)の総和。ノードk=[l,r)に着目している。
  Monoid _query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) return def;  // 交差しない
    if (a <= l && r <= b)
      return data[k];  // a,l,r,bの順で完全に含まれる
    else {
      Monoid c1 = _query(a, b, 2 * k + 1, l, (l + r) / 2);  // 左の子
      Monoid c2 = _query(a, b, 2 * k + 2, (l + r) / 2, r);  // 右の子
      return operation(c1, c2);
    }
  }

 public:
  // _n:必要サイズ, _def:初期値かつ単位元, _operation:クエリ関数,
  // _update:更新関数
  SegTree(size_t _n, Monoid _def, function<Monoid(Monoid, Monoid)> _operation,
          function<Monoid(Monoid, Monoid)> _update)
      : def(_def), operation(_operation), update(_update) {
    n = 1;
    while (n < _n) {
      n *= 2;
    }
    data = vector<Monoid>(2 * n - 1, def);
  }

  // 場所i(0-indexed)の値をxで更新
  void change(int i, Monoid x) {
    i += n - 1;
    data[i] = update(data[i], x);
    while (i > 0) {
      i = (i - 1) / 2;
      data[i] = operation(data[i * 2 + 1], data[i * 2 + 2]);
    }
  }

  // [a, b)の区間クエリを実行
  Monoid query(int a, int b) { return _query(a, b, 0, 0, n); }

  // 添字でアクセス
  Monoid operator[](int i) { return data[i + n - 1]; }
};

int main() {
  int n, Q;
  cin >> n >> Q;
  // 要素数n・long long型・区間min・点更新
  SegTree<ll> st(
      n, (1LL << 31) - 1, [](ll a, ll b) { return min(a, b); },
      [](ll a, ll b) { return b; });
  rep(q, Q) {
    int c, x, y;
    cin >> c >> x >> y;
    if (c == 0) {
      // update(x, y)
      st.change(x, y);
    } else {
      // find(s, t)
      cout << st.query(x, y + 1) << endl;
    }
  }

  return 0;
}