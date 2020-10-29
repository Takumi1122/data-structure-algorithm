#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 強連結成分分解 O(|V|+|E|)
// 蟻本P287: Popular Cows

struct SCC {
  using Edge = int;
  using SGraph = vector<vector<Edge>>;

  // input
  SGraph G, rG;

  // result
  vector<vector<int>> scc;
  vector<int> cmp;
  SGraph dag;

  // constructor
  SCC(int n) : G(n), rG(n) {}

  // add edge
  void addedge(int u, int v) {
    G[u].push_back(v);
    rG[v].push_back(u);
  }

  // decomp
  vector<bool> seen;
  vector<int> vs, rvs;
  void dfs(int v) {
    seen[v] = true;
    for (auto e : G[v])
      if (!seen[e]) dfs(e);
    vs.push_back(v);
  }
  void rdfs(int v, int k) {
    seen[v] = true;
    cmp[v] = k;
    for (auto e : rG[v])
      if (!seen[e]) rdfs(e, k);
    rvs.push_back(v);
  }

  // reconstruct
  set<pair<int, int>> newEdges;
  void reconstruct() {
    int n = (int)G.size();
    int dV = (int)scc.size();
    dag.assign(dV, vector<Edge>());
    newEdges.clear();
    for (int i = 0; i < n; ++i) {
      int u = cmp[i];
      for (auto e : G[i]) {
        int v = cmp[e];
        if (u == v) continue;
        if (!newEdges.count({u, v})) {
          dag[u].push_back(v);
          newEdges.insert({u, v});
        }
      }
    }
  }

  // main
  void solve() {
    // first dfs
    int n = (int)G.size();
    seen.assign(n, false);
    vs.clear();
    for (int v = 0; v < n; ++v)
      if (!seen[v]) dfs(v);

    // back dfs
    int k = 0;
    scc.clear();
    cmp.assign(n, -1);
    seen.assign(n, false);
    for (int i = n - 1; i >= 0; --i) {
      if (!seen[vs[i]]) {
        rvs.clear();
        rdfs(vs[i], k++);
        scc.push_back(rvs);
      }
    }

    // reconstruct
    reconstruct();
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  SCC scc(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    scc.addedge(a, b);
  }
  scc.solve();

  int size = scc.scc.size();

  // 候補となる点の数を調べる
  int u = 0, num = 0;
  rep(i, n) {
    if (scc.cmp[i] == size - 1) {
      u = i;
      num++;
    }
  }

  scc.scc.clear();
  scc.rvs.clear();
  scc.cmp.assign(n, -1);
  scc.seen.assign(n, false);
  scc.rdfs(u, 0);
  rep(i, n) {
    if (!scc.seen[i]) {
      num = 0;
      break;
    }
  }

  cout << num << endl;
}