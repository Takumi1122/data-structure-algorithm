#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

/*
    参考リンク
    ABC 187 F - Close Group
      https://atcoder.jp/contests/abc187/tasks/abc187_f
*/

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const int INF = 1001001001;

int main() {
  int n, m;
  cin >> n >> m;
  Graph g(n, vector<int>(n));
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a][b] = g[b][a] = 1;
  }

  int n2 = 1 << n;
  // ok[bit]: 頂点集合bitがクリークかどうか O(2^n * n^2)
  vector<bool> ok(n2, true);
  rep(s, n2) {
    vector<int> vs;
    rep(i, n) if (s & (1 << i)) vs.push_back(i);
    rep(i, vs.size()) {
      for (int j = i + 1; j < vs.size(); ++j) {
        if (!g[vs[i]][vs[j]]) ok[s] = false;
      }
    }
  }

  // dp[bit]: O(3^n)
  // bitに対応する頂点集合をいくつかのクリークに分割するとき、分割されたクリークの個数の最小値
  vector<int> dp(n2, INF);
  dp[0] = 0;

  rep(s, n2) {
    if (dp[s] >= INF) continue;
    // 補集合
    int cs = (n2 - 1) - s;
    // 部分集合の部分集合を調べる
    for (int add = cs;; add = (add - 1) & cs) {
      if (!add) break;
      if (ok[add]) chmin(dp[s | add], dp[s] + 1);
    }
  }

  cout << dp[(n2)-1] << endl;
  return 0;
}