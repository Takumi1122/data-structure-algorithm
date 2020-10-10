#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<P>>;

const ll INF = (1LL << 60);

// ダイクストラ法 O((|V|+|E|)log|V|)

/*
    参考リンク
    AIZU ONLINE JUDGE
      https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A
*/

// n: 頂点数 m: 辺数 r: 始点
int n, m, r;
Graph G;

void dijkstra() {
  priority_queue<P, vector<P>, greater<P>> pq;
  vector<ll> d(n, INF);

  d[r] = 0;
  pq.push(make_pair(0, r));

  while (!pq.empty()) {
    P f = pq.top();
    pq.pop();
    int u = f.second;

    // 最小値を取り出し、それが最短でなければ無視
    if (d[u] < f.first) continue;

    for (auto e : G[u]) {
      int v = e.first;
      if (d[v] > d[u] + e.second) {
        d[v] = d[u] + e.second;
        pq.push(make_pair(d[v], v));
      }
    }
  }

  rep(i, n) {
    if (d[i] == INF) {
      cout << "INF" << endl;
    } else {
      cout << d[i] << endl;
    }
  }
}

int main() {
  cin >> n >> m >> r;
  G.assign(n, vector<P>());
  rep(i, m) {
    int s, t, c;
    cin >> s >> t >> c;
    G[s].push_back(make_pair(t, c));
  }

  dijkstra();

  return 0;
}