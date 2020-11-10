#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// ベルマンフォード法 O(|V||E|)
// 頂点0から到達可能であり, n−1 に到達可能である

/*
    参考リンク
    ABC 137 E - Coins Respawn
      https://atcoder.jp/contests/abc137/tasks/abc137_e
*/

// 頂点0から到達可能な頂点を求める
vector<bool> seen1;
void dfs(const Graph &G, int v) {
  seen1[v] = true;
  for (auto next_v : G[v]) {
    if (seen1[next_v]) continue;
    dfs(G, next_v);
  }
}
// 頂点 n-1 に到達可能な頂点を求める
vector<bool> seen2;
void rdfs(const Graph &G, int v) {
  seen2[v] = true;
  for (auto next_v : G[v]) {
    if (seen2[next_v]) continue;
    rdfs(G, next_v);
  }
}
// 頂点0から到達可能であり, n−1 に到達可能である
vector<bool> ok;

struct Edge {
  ll from;
  ll to;
  ll cost;
  Edge(ll from, ll to, ll cost) : from(from), to(to), cost(cost) {}
};

using Edges = vector<Edge>;
const ll INF = 1LL << 60;

bool bellman_ford(const Edges &Es, int V, int s, vector<ll> &dis) {
  dis.resize(V, INF);
  dis[s] = 0;
  int cnt = 0;
  while (cnt < V) {
    bool end = true;
    for (auto e : Es) {
      if (!ok[e.from]) continue;
      if (!ok[e.to]) continue;
      if (dis[e.from] != INF && dis[e.from] + e.cost < dis[e.to]) {
        dis[e.to] = dis[e.from] + e.cost;
        end = false;
      }
    }
    if (end) break;
    cnt++;
  }
  return (cnt == V);
}

int main() {
  int n, m, p;
  cin >> n >> m >> p;
  Graph g1(n);
  Graph g2(n);
  Edges edges;
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    Edge edge(a, b, -c + p);
    edges.push_back(edge);
    g1[a].push_back(b);
    g2[b].push_back(a);
  }

  seen1.assign(n, false);
  dfs(g1, 0);
  seen2.assign(n, false);
  rdfs(g2, n - 1);
  ok.assign(n, false);
  rep(i, n) ok[i] = (seen1[i] && seen2[i]);

  vector<ll> dist;
  bool negative = bellman_ford(edges, n, 0, dist);

  if (negative) {
    cout << -1 << endl;
  } else {
    cout << max(-dist[n - 1], 0LL) << endl;
  }
  return 0;
}