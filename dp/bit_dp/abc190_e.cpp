#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 巡回セールスマン問題
// bfsで頂点(c[i])間の距離を求める

/*
    参考リンク
    ABC 190 E - Magical Ornament
      https://atcoder.jp/contests/abc190/tasks/abc190_e
*/

void chmin(int& x, int y) { x = min(x, y); }

int main() {
  int n, m;
  cin >> n >> m;
  Graph g(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int k;
  cin >> k;
  vector<int> c(k);
  rep(i, k) {
    cin >> c[i];
    c[i]--;
  }

  vector<vector<int>> dist(k, vector<int>(k));
  const int INF = 1001001001;
  auto bfs = [&](int sv) {
    vector<int> dist(n, INF);
    queue<int> q;
    dist[sv] = 0;
    q.push(sv);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int u : g[v]) {
        if (dist[u] != INF) continue;
        dist[u] = dist[v] + 1;
        q.push(u);
      }
    }
    return dist;
  };
  rep(i, k) {
    vector<int> d = bfs(c[i]);
    rep(j, k) dist[i][j] = d[c[j]];
  }

  int k2 = 1 << k;
  vector dp(k2, vector<int>(k, INF));
  rep(i, k) dp[1 << i][i] = 1;

  rep(s, k2) rep(i, k) {
    if (~s >> i & 1) continue;
    rep(j, k) {
      if (s >> j & 1) continue;
      chmin(dp[s | 1 << j][j], dp[s][i] + dist[i][j]);
    }
  }

  int ans = INF;
  rep(i, k) chmin(ans, dp[k2 - 1][i]);
  if (ans == INF)
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}