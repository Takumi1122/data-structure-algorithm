#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

/*
    参考リンク
    ABC 197 E - Traveler
      https://atcoder.jp/contests/abc197/tasks/abc197_e
*/

const int INF = 1001001001;
const ll LINF = 1ll << 60;

int main() {
  int n;
  cin >> n;
  vector<int> l(n, INF), r(n, -INF);
  rep(i, n) {
    int x, c;
    cin >> x >> c;
    --c;
    l[c] = min(l[c], x);
    r[c] = max(r[c], x);
  }

  vector<P> d;
  // 始まり
  d.emplace_back(0, 0);
  rep(i, n) if (l[i] != INF) d.emplace_back(l[i], r[i]);
  // 終わり
  d.emplace_back(0, 0);

  // dp[i][j]: 色iまで取って色iの左/右端で終わったときの最小値
  vector<vector<ll>> dp(d.size() + 1, vector<ll>(2, LINF));
  // 始まりについての初期化
  dp[0][0] = 0;
  dp[0][1] = 0;

  rep(i, d.size()) {
    int l = d[i + 1].first, r = d[i + 1].second;
    rep(j, 2) {
      int x = j ? d[i].second : d[i].first;
      dp[i + 1][0] = min(dp[i + 1][0], dp[i][j] + abs(x - r) + (r - l));
      dp[i + 1][1] = min(dp[i + 1][1], dp[i][j] + abs(x - l) + (r - l));
    }
  }

  cout << dp[d.size()][0] << endl;
  return 0;
}