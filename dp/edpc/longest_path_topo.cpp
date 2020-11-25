#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// DAG 上の DP
// 更新順序が非自明な場合にはメモ化再帰が有効
// トポロジカルソート

/*
    参考リンク
    Educational DP Contest G - Longest Path
      https://atcoder.jp/contests/dp/tasks/dp_g
*/

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

const ll INF = 1LL << 60;

int dp[100100];
int main() {
  int n, m;
  cin >> n >> m;
  Graph G(n);
  vector<int> deg(n);  // 各頂点の入次数
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    G[x].push_back(y);
    deg[y]++;
  }

  // source をキューに突っ込む
  queue<int> que;
  rep(v, n) if (deg[v] == 0) que.push(v);

  // BFS
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (auto nv : G[v]) {
      deg[nv]--;  // エッジ (v, nv) を破壊する
      if (deg[nv] == 0) {
        que.push(nv);
        chmax(dp[nv], dp[v] + 1);
      }
    }
  }

  int ans = 0;
  rep(v, n) chmax(ans, dp[v]);
  cout << ans << endl;
}