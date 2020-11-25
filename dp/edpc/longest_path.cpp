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
Graph G;
// ノード v を始点としたときの、G の有効パスの長さの最大値
int dp[100100];

int rec(int v) {
  if (dp[v] != -1) return dp[v];

  int res = 0;
  for (auto nv : G[v]) {
    chmax(res, rec(nv) + 1);
  }
  return dp[v] = res;
}

int main() {
  int n, m;
  cin >> n >> m;
  G.assign(n, vector<int>());
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    G[x].push_back(y);
  }

  rep(v, n) dp[v] = -1;

  int ans = 0;
  rep(v, n) chmax(ans, rec(v));
  cout << ans << endl;
}