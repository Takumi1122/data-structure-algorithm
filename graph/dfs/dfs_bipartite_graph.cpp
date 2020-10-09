#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 二部グラフ判定

vector<int> color;
bool dfs(const Graph &G, int v, int cur = 0) {
  color[v] = cur;
  for (auto next_v : G[v]) {
    // 隣接頂点がすでに色確定していた場合
    if (color[next_v] != -1) {
      if (color[next_v] == cur) return false;  // 同じ色が隣接したらダメ
      continue;
    }

    // 隣接頂点の色を変えて、再帰的に探索 (一回でも false が返ってきたら false)
    if (!dfs(G, next_v, 1 - cur)) return false;
  }
  return true;
}

int main() {
  // 頂点数と辺数
  int n, m;
  cin >> n >> m;

  // グラフ入力受取
  Graph G(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  // 探索
  color.assign(n, -1);
  bool is_bipartite = true;
  rep(v, n) {
    if (color[v] != -1) continue;  // v が探索済みだったらスルー
    if (!dfs(G, v)) is_bipartite = false;
  }

  if (is_bipartite)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}