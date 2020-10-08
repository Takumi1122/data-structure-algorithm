#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 連結成分の個数

int main() {
  // 頂点数と辺数
  int n, m;
  cin >> n >> m;

  // グラフ入力受取 (ここでは無向グラフを想定)
  Graph G(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  // 頂点 s をスタートとした探索
  vector<int> dist(n, -1);
  queue<int> que;
  int count = 0;
  rep(v, n) {
    if (dist[v] != -1) continue;  // v が探索済みならスルー
    dist[v] = 0, que.push(v);
    while (!que.empty()) {
      int v = que.front();
      que.pop();
      for (auto nv : G[v]) {
        if (dist[nv] == -1) {
          dist[nv] = dist[v] + 1;
          que.push(nv);
        }
      }
    }
    ++count;
  }
  cout << count << endl;
}
