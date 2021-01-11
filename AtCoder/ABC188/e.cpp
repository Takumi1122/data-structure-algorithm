#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// DAGでのDP

/*
    参考リンク
    ABC 188 E - Peddler
      https://atcoder.jp/contests/abc188/tasks/abc188_e
*/

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> x(n);
  rep(i, n) cin >> x[i];
  Graph G(n);
  rep(i, m) {
    // a < b なのでDAG
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    G[a].push_back(b);
  }

  const int INF = 1001001001;
  // dp[v]: どこかで買って,一本以上たどって,今vにいるときの支出の最小値
  vector<int> dp(n, INF * 2);
  int ans = -INF;
  rep(i, n) {
    ans = max(ans, x[i] - dp[i]);
    for (int j : G[i]) {
      dp[j] = min(dp[j], dp[i]);
      dp[j] = min(dp[j], x[i]);
    }
  }

  cout << ans << endl;
  return 0;
}