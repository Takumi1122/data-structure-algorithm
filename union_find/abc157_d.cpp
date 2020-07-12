#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

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

using pint = pair<int, int>;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<set<int> > dame(n);
  UnionFind uf(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    dame[a].insert(b);
    dame[b].insert(a);
    uf.merge(a, b);
  }
  rep(i, k) {
    int c, d;
    cin >> c >> d;
    --c, --d;
    if (!uf.issame(c, d)) continue;
    dame[c].insert(d);
    dame[d].insert(c);
  }

  rep(i, n) {
    int mem = uf.size(i) - 1;  // 同じ連結成分の「自分以外」の人数
    mem -= dame[i].size();  // その中ですでに友達かブロック関係の人数
    cout << mem << " ";
  }
  cout << endl;
}