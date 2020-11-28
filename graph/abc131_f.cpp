#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 完全二部グラフを作る
// 「二次元平面状の座標」を二部グラフで表現

/*
    参考リンク
    ABC 131 F - Must Be Rectangular!
      https://atcoder.jp/contests/abc131/tasks/abc131_f
*/

struct UnionFind {
  vector<int> par;

  UnionFind(int n) : par(n, -1) {}
  void init(int n) { par.assign(n, -1); }

  int root(int x) {
    if (par[x] < 0)
      return x;
    else
      return par[x] = root(par[x]);
  }

  bool issame(int x, int y) { return root(x) == root(y); }

  bool merge(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (par[x] > par[y]) swap(x, y);  // merge technique
    par[x] += par[y];
    par[y] = x;
    return true;
  }

  int size(int x) { return -par[root(x)]; }
};

const ll MAX = 110000;

int main() {
  int n;
  cin >> n;
  vector<ll> x(n);
  vector<ll> y(n);
  UnionFind uf(MAX * 2);
  rep(i, n) {
    cin >> x[i] >> y[i];
    uf.merge(x[i], y[i] + MAX);
  }
  // 連結成分ごとに、左ノードと右ノードの個数を数える
  map<ll, ll> mx, my;
  rep(i, MAX) mx[uf.root(i)]++;
  for (int i = MAX; i < MAX * 2; ++i) my[uf.root(i)]++;
  ll ans = 0;
  for (int r = 0; r < MAX * 2; ++r) ans += mx[r] * my[r];
  ans = ans - n;
  cout << ans << endl;
}