#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// N個の値の中から1個だけ取り除いたN−1個の整数の最大公約数の最大値を求めよ

/*
    参考リンク
    ABC 125 C - GCD on Blackboard
      https://atcoder.jp/contests/abc125/tasks/abc125_c
*/

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class Monoid>
class SegTree {
  int n;
  vector<Monoid> data;
  Monoid def;
  function<Monoid(Monoid, Monoid)> operation;
  function<Monoid(Monoid, Monoid)> update;

  Monoid _query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) return def;
    if (a <= l && r <= b)
      return data[k];
    else {
      Monoid c1 = _query(a, b, 2 * k + 1, l, (l + r) / 2);
      Monoid c2 = _query(a, b, 2 * k + 2, (l + r) / 2, r);
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

// O(log(a)) a < b の場合
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
  int n;
  cin >> n;
  SegTree<ll> st(
      n, 0, [](ll a, ll b) { return gcd(a, b); }, [](ll a, ll b) { return b; });

  vector<int> a(n);
  rep(i, n) {
    cin >> a[i];
    st.change(i, a[i]);
  }

  ll ans = 0;
  rep(i, n) {
    ll l = st.query(0, i);
    ll r = st.query(i + 1, n);
    chmax(ans, gcd(l, r));
  }

  cout << ans << endl;
  return 0;
}