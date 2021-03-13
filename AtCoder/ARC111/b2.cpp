#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// UnionFindに各頂点の次数を追加

/*
    参考リンク
    ARC 111 B - Reversible Cards
      https://atcoder.jp/contests/arc111/tasks/arc111_b
*/

struct UnionFind {
  vector<int> par;
  vector<int> deg;
  UnionFind(int n) : par(n, -1), deg(n, 0) {}

  int root(int x) {
    if (par[x] < 0)
      return x;
    else
      return par[x] = root(par[x]);
  }

  bool issame(int x, int y) { return root(x) == root(y); }

  bool merge(int x, int y) {
    int x1 = x;
    int y1 = y;
    deg[x1]++;
    deg[y1]++;
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

const int numC = 4e5;

int main() {
  int n;
  cin >> n;
  UnionFind uf(numC);
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    uf.merge(a, b);
  }

  map<int, int> mp;
  rep(i, numC) {
    int x = uf.root(i);
    int d = uf.deg[i];
    mp[x] += d;
  }

  ll ans = 0;
  for (auto p : mp) {
    // (次数の合計/2) は連結成分の辺の数
    int e = p.second / 2;
    int sz = uf.size(p.first);
    if (e >= sz) {
      ans += sz;
    } else {
      ans += sz - 1;
    }
  }

  cout << ans << endl;
  return 0;
}