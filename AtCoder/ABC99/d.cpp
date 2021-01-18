#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 全処理 + 全探索

/*
    参考リンク
    ABC 99 D - Good Grid
      https://atcoder.jp/contests/abc099/tasks/abc099_d
*/

int main() {
  int n, c;
  cin >> n >> c;
  vector<vector<int>> d(c, vector<int>(c));
  rep(i, c) rep(j, c) cin >> d[i][j];
  vector<vector<int>> fi(n, vector<int>(n));
  rep(i, n) rep(j, n) cin >> fi[i][j], --fi[i][j];

  // 前処理
  vector<vector<int>> cost(3, vector<int>(c));
  rep(k, c) rep(i, n) rep(j, n) cost[(i + j) % 3][k] += d[fi[i][j]][k];

  int ans = 1 << 30;
  int ci[3];
  for (ci[0] = 0; ci[0] < c; ++ci[0]) {
    for (ci[1] = 0; ci[1] < c; ++ci[1]) {
      if (ci[1] == ci[0]) continue;
      for (ci[2] = 0; ci[2] < c; ++ci[2]) {
        if (ci[2] == ci[0] || ci[2] == ci[1]) continue;
        int tmp = 0;
        rep(i, 3) tmp += cost[i][ci[i]];
        ans = min(ans, tmp);
      }
    }
  }

  cout << ans << endl;
  return 0;
}