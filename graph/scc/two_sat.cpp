#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 2-SAT(充足可能性問題)
// 蟻本P288

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
  // 論理式 (a or not(b)) and (b or c) and (not(c) or not(a))
  int n = 6;
  SCC scc(n);
  scc.addedge(3, 4);
  scc.addedge(1, 0);
  scc.addedge(4, 2);
  scc.addedge(5, 1);
  scc.addedge(2, 3);
  scc.addedge(0, 5);

  scc.solve();

  rep(i, 3) {
    if (scc.cmp[i] == scc.cmp[i + 3]) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  rep(i, 3) {
    if (scc.cmp[i] > scc.cmp[i + 3]) {
      cout << "true" << endl;
    } else {
      cout << "false" << endl;
    }
  }
  return 0;
}