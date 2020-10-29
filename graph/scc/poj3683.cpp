#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 2-SAT(充足可能性問題)
// 蟻本P290: Priest John's Busiest Day

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
  int n;
  cin >> n;
  vector<int> s(n);
  vector<int> t(n);
  vector<int> d(n);
  rep(i, n) cin >> s[i] >> t[i] >> d[i];

  SCC scc(n * 2);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (min(s[i] + d[i], s[j] + d[j]) > max(s[i], s[j])) {
        // (not(x_i) or not(x_j)) : x_i => not(x_j) and x_j => not(x_i)
        scc.addedge(i, n + j);
        scc.addedge(j, n + i);
      }
      if (min(s[i] + d[i], t[j]) > max(s[i], t[j] - d[j])) {
        // (not(x_i) or x_j) : x_i => x_j and not(x_j) => not(x_i)
        scc.addedge(i, j);
        scc.addedge(n + j, n + i);
      }
      if (min(t[i], s[j] + d[j]) > max(t[i] - d[i], s[j])) {
        // (x_i or not(x_j)) : not(x_i) => not(x_j) and x_j => x_i
        scc.addedge(n + i, n + j);
        scc.addedge(j, i);
      }
      if (min(t[i], t[j]) > max(t[i] - d[i], t[j] - d[j])) {
        // (x_i or x_j) : not(x_i) => x_j and not(x_j) => x_i
        scc.addedge(n + i, j);
        scc.addedge(n + j, i);
      }
    }
  }
  scc.solve();

  rep(i, n) {
    if (scc.cmp[i] == scc.cmp[n + i]) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  rep(i, n) {
    if (scc.cmp[i] > scc.cmp[n + i]) {
      printf("%02d:%02d %02d:%02d\n", s[i] / 60, s[i] % 60, (s[i] + d[i]) / 60,
             (s[i] + d[i]) % 60);
    } else {
      printf("%02d:%02d %02d:%02d\n", (t[i] - d[i]) / 60, (t[i] - d[i]) % 60,
             t[i] / 60, t[i] % 60);
    }
  }
  return 0;
}