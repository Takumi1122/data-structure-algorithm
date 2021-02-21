#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll, int>;

// ダイクストラ法 O((|V|+|E|)log|V|)

/*
    参考リンク
    AIZU ONLINE JUDGE
      https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A
*/

struct Edge {
  int to, d;
  Edge(int to, int d) : to(to), d(d) {}
};

const ll INF = (1LL << 60);

int main() {
  int n, m, r;
  cin >> n >> m >> r;
  vector<vector<Edge>> g(n);
  rep(i, m) {
    int s, t, d;
    cin >> s >> t >> d;
    g[s].emplace_back(t, d);
  }

  vector<ll> dist(n, INF);
  priority_queue<P, vector<P>, greater<P>> q;
  auto push = [&](int v, ll d) {
    if (dist[v] <= d) return;
    dist[v] = d;
    q.emplace(d, v);
  };
  push(r, 0);

  while (!q.empty()) {
    ll d = q.top().first;
    int v = q.top().second;
    q.pop();
    if (dist[v] != d) continue;
    for (auto e : g[v]) {
      ll nd = d + e.d;
      push(e.to, nd);
    }
  }

  rep(i, n) {
    if (dist[i] == INF) {
      cout << "INF" << endl;
    } else {
      cout << dist[i] << endl;
    }
  }
  return 0;
}