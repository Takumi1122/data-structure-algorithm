#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// トポロジカルソート
// DAG : サイクルのない有向グラフ
// 出次数 deg[v]： 頂点vを始点とする辺の個数
// シンク： 出次数が0であるような頂点

int main() {
  int n, m;
  cin >> n >> m;

  Graph G(n);
  vector<int> deg(n, 0);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    // 逆向きに辺を張る
    G[b].push_back(a);
    deg[a]++;
  }

  // シンクたちをキューに挿入する
  queue<int> que;
  rep(i, n) if (deg[i] == 0) que.push(i);

  vector<int> order;
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    order.push_back(v);

    for (auto nv : G[v]) {
      // 辺 (nv, v) を削除する
      --deg[nv];
      if (deg[nv] == 0) que.push(nv);
    }
  }

  reverse(order.begin(), order.end());
  for (auto v : order) cout << v << endl;
  return 0;
}