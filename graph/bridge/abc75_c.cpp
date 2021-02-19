#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 無向連結グラフにおいて、「取り除いたときにグラフ全体が非連結になるような辺」を橋と言います
// O(V+E)

/*
    参考リンク
    ABC 75 C - Bridge
      https://atcoder.jp/contests/abc075/tasks/abc075_c
*/

template <typename G>
struct LowLink {
  const G &g;
  vector<int> used, ord, low;
  vector<int> articulation;
  vector<P> bridge;

  LowLink(const G &g) : g(g) {}

  int dfs(int idx, int k, int par) {
    used[idx] = true;
    ord[idx] = k++;
    low[idx] = ord[idx];
    bool is_articulation = false;
    int cnt = 0;
    for (auto &to : g[idx]) {
      if (!used[to]) {
        ++cnt;
        k = dfs(to, k, idx);
        low[idx] = min(low[idx], low[to]);
        // ~(-1) = 0
        is_articulation |= ~par && low[to] >= ord[idx];
        if (ord[idx] < low[to]) bridge.emplace_back(minmax(idx, (int)to));
      } else if (to != par) {
        low[idx] = min(low[idx], ord[to]);
      }
    }
    is_articulation |= par == -1 && cnt > 1;
    if (is_articulation) articulation.push_back(idx);
    return k;
  }

  void build() {
    used.assign(g.size(), 0);
    ord.assign(g.size(), 0);
    low.assign(g.size(), 0);
    int k = 0;
    rep(i, g.size()) {
      if (!used[i]) k = dfs(i, k, -1);
    }
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  Graph g(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  LowLink<Graph> lowlink(g);
  lowlink.build();
  cout << lowlink.bridge.size() << endl;
}