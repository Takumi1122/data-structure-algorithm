#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 行きがけ順と帰りがけ順

vector<bool> seen;
vector<int> first_order;  // 行きがけ順
vector<int> last_order;   // 帰りがけ順

void dfs(const Graph& G, int v, int& first_ptr, int& last_ptr) {
  // 行きがけ順をインクリメントしながらメモ
  first_order[v] = first_ptr++;

  seen[v] = true;
  for (auto next_v : G[v]) {
    if (seen[next_v]) continue;
    dfs(G, next_v, first_ptr, last_ptr);
  }

  // 帰りがけ順をインクリメントしながらメモ
  last_order[v] = last_ptr++;
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
  first_order.resize(n);
  last_order.resize(n);
  int first_ptr = 0, last_ptr = 0;
  dfs(G, 0, first_ptr, last_ptr);

  // 各頂点 v の行きがけ順、帰りがけ順を出力
  rep(v, n) cout << v << ": " << first_order[v] << ", " << last_order[v]
                 << endl;
}