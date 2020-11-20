#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 頂点を拡張する

/*
    参考リンク
    ABC 132 E - Hopscotch Addict
      https://atcoder.jp/contests/abc132/tasks/abc132_e
*/

int main() {
  int n, m;
  cin >> n >> m;
  Graph G(n);
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
  }
  int s, t;
  cin >> s >> t;
  s--;
  t--;

  vector<vector<ll>> dist(n, vector<ll>(3, -1));
  dist[s][0] = 0;
  queue<P> que;
  que.push({s, 0});
  while (!que.empty()) {
    P cur = que.front();
    que.pop();
    int v = cur.first;
    int parity = cur.second;
    for (auto nv : G[v]) {
      int np = (parity + 1) % 3;
      if (dist[nv][np] == -1) {
        dist[nv][np] = dist[v][parity] + 1;
        que.push({nv, np});
      }
    }
  }

  if (dist[t][0] == -1)
    cout << -1 << endl;
  else
    cout << dist[t][0] / 3 << endl;
  return 0;
}