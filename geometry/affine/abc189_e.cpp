#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

// アフィン変換
// 行列演算

/*
    参考リンク
    ABC 189 E - Rotate and Flip
      https://atcoder.jp/contests/abc189/tasks/abc189_e
*/

struct A {
  vector<vector<int>> a;
  vector<ll> b;
  A(const vector<vector<int>>& _a = {{1, 0}, {0, 1}},
    const vector<ll>& _b = {0, 0})
      : a(_a), b(_b) {}

  A operator*(const A& x) const {
    A res({{0, 0}, {0, 0}});
    // res.aの計算
    rep(i, 2) rep(j, 2) rep(k, 2) { res.a[i][j] += x.a[i][k] * a[k][j]; }

    // res.bの計算
    res.b = A(x.a) * b;
    rep(i, 2) res.b[i] += x.b[i];

    return res;
  }

  vector<ll> operator*(const vector<ll>& x) const {
    vector<ll> res = b;
    rep(i, 2) rep(j, 2) res[i] += a[i][j] * x[j];
    return res;
  }
};

int main() {
  int n;
  cin >> n;
  vector<vector<ll>> p(n, vector<ll>(2));
  rep(i, n) cin >> p[i][0] >> p[i][1];

  int m;
  cin >> m;
  vector<A> d(1);
  rep(i, m) {
    int op;
    cin >> op;
    A x;
    if (op == 1) {
      // 時計回りに90度回転
      x = A({{0, 1}, {-1, 0}});
    } else if (op == 2) {
      // 反時計回りに90度回転
      x = A({{0, -1}, {1, 0}});
    } else {
      int p;
      cin >> p;
      if (op == 3)
        // 直線 x = p について対称な位置に移動
        x = A({{-1, 0}, {0, 1}}, {2 * p, 0});
      else
        // 直線 y = p について対称な位置に移動
        x = A({{1, 0}, {0, -1}}, {0, 2 * p});
    }
    A y = d.back();
    d.emplace_back(y * x);
  }

  int q;
  cin >> q;
  rep(i, q) {
    int a, b;
    cin >> a >> b;
    --b;
    vector<ll> ans = d[a] * p[b];
    printf("%lld %lld\n", ans[0], ans[1]);
  }
  return 0;
}