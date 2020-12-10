#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 165 F - LIS on Tree
      https://atcoder.jp/contests/abc165/tasks/abc165_f
*/

const int MAX_N = 200005;
const int INF = 1001001001;

vector<int> a, ans;
vector<int> to[MAX_N];
// dp[i]: 長さiの増加部分列の末尾として考えられるmin
int dp[MAX_N];

void dfs(int v, int p = -1) {
  int i = lower_bound(dp, dp + MAX_N, a[v]) - dp;
  int old = dp[i];
  dp[i] = a[v];
  ans[v] = i;
  if (p != -1) ans[v] = max(ans[v], ans[p]);
  for (int u : to[v]) {
    if (u == p) continue;
    dfs(u, v);
  }
  // rollback
  dp[i] = old;
}

int main() {
  int n;
  cin >> n;
  a = ans = vector<int>(n);
  rep(i, n) cin >> a[i];
  rep(i, n - 1) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    to[v].push_back(u);
    to[u].push_back(v);
  }

  rep(i, MAX_N) dp[i] = INF;
  dp[0] = -INF;
  dfs(0);

  rep(i, n) cout << ans[i] << endl;
  return 0;
}