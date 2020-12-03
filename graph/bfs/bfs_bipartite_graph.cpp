#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 二部グラフ判定
// dist の値が等しい頂点同士が隣接することはない

int main() {
  int n, m;
  cin >> n >> m;

  Graph G(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  bool is_bipartite = true;
  vector<int> dist(n, -1);
  queue<int> que;
  rep(v, n) {
    if (dist[v] != -1) continue;
    dist[v] = 0, que.push(v);
    while (!que.empty()) {
      int v = que.front();
      que.pop();
      for (auto nv : G[v]) {
        if (dist[nv] == -1) {
          dist[nv] = dist[v] + 1;
          que.push(nv);
        } else {
          // 整合性を確認する
          if (dist[v] == dist[nv]) is_bipartite = false;
        }
      }
    }
  }

  if (is_bipartite)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
