#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 任意の2頂点uとvについて、その最小共通祖先をwとすると、uとvの距離は
// (du + dv − 2*dw) と書くことができる

/*
    参考リンク
    ABC 126 D - Even Relation
      https://atcoder.jp/contests/abc126/tasks/abc126_d
*/

struct Edge {
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;

int main() {
  int n;
  cin >> n;

  Graph G(n);
  rep(i, n - 1) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    G[u].push_back(Edge(v, w));
    G[v].push_back(Edge(u, w));
  }

  vector<int> ans(n);

  vector<int> dist(n, -1);
  queue<int> que;
  dist[0] = 0;
  que.push(0);

  while (!que.empty()) {
    int v = que.front();
    que.pop();

    for (auto nv : G[v]) {
      if (dist[nv.to] != -1) continue;
      dist[nv.to] = dist[v] + nv.weight;
      que.push(nv.to);
    }
  }

  rep(i, n) {
    if (dist[i] % 2 == 0) {
      ans[i] = 0;
    } else {
      ans[i] = 1;
    }
  }

  rep(i, n) cout << ans[i] << endl;
  return 0;
}