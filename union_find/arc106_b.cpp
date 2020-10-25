#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ARC 106 B - Values
      https://atcoder.jp/contests/arc106/tasks/arc106_b
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

int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];

  UnionFind uf(n);
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    uf.merge(x, y);
  }

  vector<ll> sa(n, 0), sb(n, 0);
  rep(v, n) {
    int r = uf.root(v);
    sa[r] += a[v], sb[r] += b[v];
  }
  bool res = true;
  rep(v, n) {
    int r = uf.root(v);
    if (sa[r] != sb[r]) res = false;
  }

  if (res)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}