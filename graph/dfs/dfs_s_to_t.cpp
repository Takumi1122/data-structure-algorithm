#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// sからtへ辿り着けるか

// 深さ優先探索
vector<bool> seen;
void dfs(const Graph &G, int v) {
  seen[v] = true;

  for (auto nv : G[v]) {
    if (seen[nv]) continue;
    dfs(G, nv);
  }
}

int main() {
  int n, m, s, t;
  cin >> n >> m >> s >> t;

  Graph G(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
  }
  s--;
  t--;

  seen.assign(n, false);
  dfs(G, s);

  if (seen[t])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}