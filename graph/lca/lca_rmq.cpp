#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 最近共通祖先(LCA) オイラーツアー
// 前処理O(n)
// クエリ O(log(n))

/*
    参考リンク
    AIZU ONLINE JUDGE
      https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C
*/

class LCA {
 public:
  int n, segn;
  vector<int> path, depth, in_order;
  vector<pair<int, int>> dat;
  const pair<int, int> INF = make_pair(1000000000, 1000000000);

  LCA(const Graph &g, int root)
      : n(g.size()), path(n * 2 - 1), depth(n * 2 - 1), in_order(n) {
    int k = 0;
    dfs(g, root, -1, 0, k);
    for (segn = 1; segn < n * 2 - 1; segn <<= 1)
      ;
    dat.assign(segn * 2, INF);
    for (int i = 0; i < (int)depth.size(); ++i)
      dat[segn + i] = make_pair(depth[i], i);
    for (int i = segn - 1; i >= 1; --i)
      dat[i] = min(dat[i * 2], dat[i * 2 + 1]);
  }

  int get(int u, int v) const {
    int l = min(in_order[u], in_order[v]);
    int r = max(in_order[u], in_order[v]) + 1;
    return path[range_min(1, segn, l, r).second];
  }

  void dfs(const Graph &g, int v, int p, int d, int &k) {
    in_order[v] = k;
    path[k] = v;
    depth[k++] = d;
    for (auto &e : g[v]) {
      if (e != p) {
        dfs(g, e, v, d + 1, k);
        path[k] = v;
        depth[k++] = d;
      }
    }
  }

  pair<int, int> range_min(int v, int w, int l, int r) const {
    if (r <= l || w == 0) return INF;
    if (r - l == w) return dat[v];
    int m = w / 2;
    auto rmin = range_min(v * 2, m, l, min(r, m));
    auto lmin = range_min(v * 2 + 1, m, max(0, l - m), r - m);
    return min(rmin, lmin);
  }
};

int main() {
  int n;
  cin >> n;
  Graph G(n);
  rep(i, n) {
    int num;
    cin >> num;
    rep(j, num) {
      int c;
      cin >> c;
      G[i].push_back(c);
      G[c].push_back(i);
    }
  }

  LCA lca(G, 0);

  int q;
  cin >> q;
  rep(i, q) {
    int u, v;
    cin >> u >> v;
    cout << lca.get(u, v) << endl;
  }
  return 0;
}