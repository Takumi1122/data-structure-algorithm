#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// swap UnionFind

/*
    参考リンク
    ABC 97 D - Equals
      https://atcoder.jp/contests/abc097/tasks/arc097_b
*/

struct UnionFind {
  vector<int> par;

  UnionFind(int n) : par(n, -1) {}

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
  vector<int> p(n);
  rep(i, n) {
    cin >> p[i];
    p[i]--;
  }

  UnionFind uf(n);
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    uf.merge(x, y);
  }

  int ans = 0;
  rep(i, n) if (uf.issame(i, p[i])) ans++;

  cout << ans << endl;
  return 0;
}