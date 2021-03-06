#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int> >;

// 最近共通祖先(LCA)
// 前処理 : O(nlog(n))
// クエリ : O(log(n))

/*
    参考リンク
    AIZU ONLINE JUDGE
      https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C
*/

struct LCA {
  // v から 2^d回親を辿ったときに到達する頂点
  vector<vector<int> > parent;
  vector<int> depth;
  LCA() {}
  LCA(const Graph &G, int r = 0) { init(G, r); }
  void init(const Graph &G, int r = 0) {
    int V = (int)G.size();
    int h = 1;
    while ((1 << h) < V) ++h;
    parent.assign(h, vector<int>(V, -1));
    depth.assign(V, -1);
    dfs(G, r, -1, 0);
    for (int i = 0; i + 1 < (int)parent.size(); ++i)
      for (int v = 0; v < V; ++v)
        if (parent[i][v] != -1) parent[i + 1][v] = parent[i][parent[i][v]];
  }

  void dfs(const Graph &G, int v, int p, int d) {
    parent[0][v] = p;
    depth[v] = d;
    for (auto e : G[v])
      if (e != p) dfs(G, e, v, d + 1);
  }

  int get(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    // uとvの深さが同じになるまで親をたどる
    for (int i = 0; i < (int)parent.size(); ++i)
      if ((depth[v] - depth[u]) & (1 << i)) v = parent[i][v];
    if (u == v) return u;
    // 二分探索でLCAを求める
    for (int i = (int)parent.size() - 1; i >= 0; --i) {
      if (parent[i][u] != parent[i][v]) {
        u = parent[i][u];
        v = parent[i][v];
      }
    }
    return parent[0][u];
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

  LCA lca(G);

  int q;
  cin >> q;
  rep(i, q) {
    int u, v;
    cin >> u >> v;
    cout << lca.get(u, v) << endl;
  }
  return 0;
}