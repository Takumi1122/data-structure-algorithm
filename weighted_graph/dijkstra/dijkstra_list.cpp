#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

static const int MAX = 10000;
static const int INFTY = (1 << 21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

// 隣接リスト ヒープ o((|V|+|E|)log|v|)

int n;
vector<P> adj[MAX];  // 重み付き有向グラフの隣接リスト表現

void dijkstra() {
  priority_queue<P> pq;
  int color[MAX];
  int d[MAX];
  rep(i, n) {
    d[i] = INFTY;
    color[i] = WHITE;
  }

  d[0] = 0;
  pq.push(make_pair(0, 0));
  color[0] = GRAY;

  while (!pq.empty()) {
    P f = pq.top();
    pq.pop();
    int u = f.second;
    color[u] = BLACK;

    // 最小値を取り出し、それが最短でなければ無視
    if (d[u] < f.first * (-1)) continue;

    rep(j, adj[u].size()) {
      int v = adj[u][j].first;
      if (color[v] == BLACK) continue;
      if (d[v] > d[u] + adj[u][j].second) {
        d[v] = d[u] + adj[u][j].second;
        // priority_queueはデフォルトで大きい値を優先するためー1をかける
        pq.push(make_pair(d[v] * (-1), v));
        color[v] = GRAY;
      }
    }
  }

  rep(i, n) cout << i << " " << (d[i] == INFTY ? -1 : d[i]) << endl;
}

int main() {
  int k, u, v, c;
  // u: 頂点の番号
  // k: uの出次数
  // v: uに隣接する頂点の番号
  // c: uとvをつなぐ有向辺の重み

  cin >> n;
  rep(i, n) {
    cin >> u >> k;
    rep(j, k) {
      cin >> v >> c;
      adj[u].push_back(make_pair(v, c));
    }
  }

  dijkstra();

  return 0;
}