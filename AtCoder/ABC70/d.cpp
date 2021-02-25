#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
// ダイクストラ法ではpair<ll,int>にする
using P = pair<ll, int>;

// 頂点kを経由する

/*
    参考リンク
    ABC 70 D - Transit Tree Path
      https://atcoder.jp/contests/abc070/tasks/abc070_d
*/

struct Edge {
  int to, d;
  Edge(int to, int d) : to(to), d(d) {}
};

const ll INF = (1LL << 60);

int main() {
  int n;
  cin >> n;
  vector<vector<Edge>> g(n);
  rep(i, n - 1) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    g[a].emplace_back(b, c);
    g[b].emplace_back(a, c);
  }
  int Q, k;
  cin >> Q >> k;
  k--;

  vector<ll> dist(n, INF);
  priority_queue<P, vector<P>, greater<P>> q;
  auto push = [&](int v, ll d) {
    if (dist[v] <= d) return;
    dist[v] = d;
    q.emplace(d, v);
  };
  push(k, 0);

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

  rep(i, Q) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    ll ans = dist[y] + dist[x];
    cout << ans << endl;
  }
  return 0;
}