#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 各頂点の深さ: 行きがけ順に求めた
// 各頂点を根とした部分木のサイズ: 帰りがけ順に求めた

/*
  「子ノードについての情報を用いて、親ノードについての情報を更新する」という
  処理はしばしば木DPとよばれます
*/

vector<int> depth;
vector<int> subtree_size;

void dfs(const Graph &G, int v, int p, int d) {
  depth[v] = d;
  for (auto nv : G[v]) {
    if (nv == p) continue;
    dfs(G, nv, v, d + 1);
  }

  // 帰りがけ時に、部分木サイズを求める
  subtree_size[v] = 1;  // 自分自身
  for (auto c : G[v]) {
    if (c == p) continue;
    subtree_size[v] += subtree_size[c];
  }
}

int main() {
  int n;
  cin >> n;

  Graph G(n);
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  int root = 0;
  depth.assign(n, 0);
  subtree_size.assign(n, 0);
  dfs(G, root, -1, 0);

  rep(v, n) {
    cout << v << ": depth = " << depth[v]
         << ", subtree_size = " << subtree_size[v] << endl;
  }
}