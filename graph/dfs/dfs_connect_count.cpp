#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 深さ優先探索
vector<bool> seen;
void dfs(const Graph &G, int v) {
  seen[v] = true;
  for (auto next_v : G[v]) {
    if (seen[next_v]) continue;
    dfs(G, next_v);  // 再帰的に探索
  }
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

  // 全頂点が訪問済みになるまで探索
  int count = 0;
  seen.assign(n, false);
  rep(v, n) {
    if (seen[v]) continue;  // v が探索済みだったらスルー
    dfs(G, v);  // v が未探索なら v を始点とした DFS を行う
    ++count;
  }
  cout << count << endl;
}