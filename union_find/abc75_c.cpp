#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 無向連結グラフにおいて、「取り除いたときにグラフ全体が非連結になるような辺」を橋と言います
// O(V(V+E))

/*
    参考リンク
    ABC 75 C - Bridge
      https://atcoder.jp/contests/abc075/tasks/abc075_c
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
  vector<int> a(m), b(m);
  rep(i, m) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }

  int ans = 0;
  rep(i, m) {
    UnionFind uf(n);
    rep(j, m) {
      if (i == j) continue;
      uf.merge(a[j], b[j]);
    }
    if (!uf.issame(a[i], b[i])) ans++;
  }

  cout << ans << endl;
  return 0;
}