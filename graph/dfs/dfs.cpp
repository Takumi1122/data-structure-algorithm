#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 深さ優先探索 o(|V|+|E|)
vector<bool> seen;
void dfs(const Graph &G, int v) {
  seen[v] = true;  // v を訪問済にする

  // v から行ける各頂点 next_v について
  for (auto next_v : G[v]) {
    if (seen[next_v]) continue;  // next_v が探索済だったらスルー
    dfs(G, next_v);              // 再帰的に探索
  }
}

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

  // 頂点 0 をスタートとした探索
  seen.assign(n, false);  // 全頂点を「未訪問」に初期化
  dfs(G, 0);
}