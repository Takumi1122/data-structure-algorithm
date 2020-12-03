#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 深さ優先探索 o(|V|+|E|)

vector<bool> seen;
void dfs(const Graph &G, int v) {
  seen[v] = true;

  for (auto nv : G[v]) {
    if (seen[nv]) continue;
    dfs(G, nv);
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  Graph G(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  seen.assign(n, false);
  dfs(G, 0);
}