#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// トポロジカルソートする
void rec(int v, const Graph &G, vector<bool> &seen, vector<int> &order) {
  seen[v] = true;
  for (auto next : G[v]) {
    if (seen[next]) continue;  // 既に訪問済みなら探索しない
    rec(next, G, seen, order);
  }
  order.push_back(v);
}

int main() {
  int n, m;
  cin >> n >> m;  // 頂点数と枝数
  Graph G(n);     // 頂点数 N のグラフ
  rep(i, m) {
    int a, b;
    cin >> a >> b;  // ノード a からノード b へと有向辺を張る
    a--;
    b--;
    G[a].push_back(b);
  }

  // 探索
  vector<bool> seen(n, 0);  // 初期状態では全ノードが未訪問
  vector<int> order;        // トポロジカルソート順
  rep(v, n) {
    if (seen[v]) continue;  // 既に訪問済みなら探索しない
    rec(v, G, seen, order);
  }
  reverse(order.begin(), order.end());  // 逆順に

  // 出力
  for (auto v : order) cout << v << " -> ";
  cout << endl;
}