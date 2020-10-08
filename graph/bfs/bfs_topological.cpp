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
  // 頂点数と辺数
  int n, m;
  cin >> n >> m;

  // グラフ入力受取
  Graph G(n);
  vector<int> deg(n, 0);  // 各頂点の出次数
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[b].push_back(a);  // 逆向きに辺を張る
    deg[a]++;           // 出次数
  }

  // シンクたちをキューに挿入する
  queue<int> que;
  rep(i, n) if (deg[i] == 0) que.push(i);

  // 探索開始
  vector<int> order;
  while (!que.empty()) {
    // キューから頂点を取り出す
    int v = que.front();
    que.pop();
    order.push_back(v);

    // v へと伸びている頂点たちを探索する
    for (auto nv : G[v]) {
      // 辺 (nv, v) を削除する
      --deg[nv];

      // それによって nv が新たにシンクになったらキューに挿入
      if (deg[nv] == 0) que.push(nv);
    }
  }

  // 答えをひっくり返す
  reverse(order.begin(), order.end());
  for (auto v : order) cout << v << endl;
}