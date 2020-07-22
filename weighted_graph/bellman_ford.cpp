#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// ベルマンフォード法 o(|V||E|)
// 負の辺が含まれているような場合でも適用可能
// 負の閉路がグラフに含まれている際はそれを検出することができる

struct Edge {
  ll from;
  ll to;
  ll cost;
  Edge(ll from, ll to, ll cost) : from(from), to(to), cost(cost) {}
};

using Edges = vector<Edge>;
const ll INF = 1LL << 60;

/* bellman_ford(Es,s,t,dis)
    入力: 全ての辺Es, 頂点数V, 開始点 s, 最短経路を記録するdis
    出力: 負の閉路が存在するなら ture
    計算量：O(|E||V|)
    副作用：dis が書き換えられる
*/
bool bellman_ford(const Edges &Es, int V, int s, vector<ll> &dis) {
  dis.resize(V, INF);
  dis[s] = 0;
  int cnt = 0;
  while (cnt < V) {
    bool end = true;
    for (auto e : Es) {
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
  int v, e, r;
  cin >> v >> e >> r;
  Edges edges;
  rep(i, e) {
    int s, t, d;
    cin >> s >> t >> d;
    Edge edge(s, t, d);
    edges.push_back(edge);
  }
  vector<ll> dist;
  bool negative = bellman_ford(edges, v, r, dist);

  if (negative) {
    cout << "NEGATIVE CYCLE" << endl;
  } else {
    rep(i, v) {
      if (dist[i] == INF) {
        cout << "INF" << endl;
      } else {
        cout << dist[i] << endl;
      }
    }
  }
}