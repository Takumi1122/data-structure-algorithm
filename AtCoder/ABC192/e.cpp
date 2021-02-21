#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<ll, int>;

/*
    参考リンク
    ABC 192 E - Train
      https://atcoder.jp/contests/abc192/tasks/abc192_e
*/

struct Edge {
  int to, t, k;
  Edge(int to, int t, int k) : to(to), t(t), k(k) {}
};

const ll INF = 1e18;

int main() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  x--;
  y--;
  vector<vector<Edge>> g(n);
  rep(i, m) {
    int a, b, t, k;
    cin >> a >> b >> t >> k;
    --a;
    --b;
    g[a].emplace_back(b, t, k);
    g[b].emplace_back(a, t, k);
  }

  vector<ll> dist(n, INF);
  priority_queue<P, vector<P>, greater<P>> q;
  auto push = [&](int v, ll x) {
    if (dist[v] <= x) return;
    dist[v] = x;
    q.emplace(x, v);
  };
  push(x, 0);

  while (!q.empty()) {
    ll x = q.top().first;
    int v = q.top().second;
    q.pop();
    if (dist[v] != x) continue;
    for (auto e : g[v]) {
      ll nx = (x + e.k - 1) / e.k * e.k + e.t;
      push(e.to, nx);
    }
  }

  ll ans = dist[y];
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}