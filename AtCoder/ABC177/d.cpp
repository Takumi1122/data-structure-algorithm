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

int main() {
  int n, m;
  cin >> n >> m;
  UnionFind uf(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    uf.merge(a, b);
  }

  ll ans = 0;
  rep(i, n) {
    ll mem = uf.size(i);
    ans = max(ans, mem);
  }
  cout << ans << endl;
}