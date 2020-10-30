#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 最大正方形(Largest Square) O(H * W)

/*
    参考リンク
    AIZU ONLINE JUDGE
      https://onlinejudge.u-aizu.ac.jp/problems/DPL_3_A
*/

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> c(h, vector<int>(w, 0));
  vector<vector<int>> dp(h, vector<int>(w, 0));

  rep(i, h) rep(j, w) cin >> c[i][j];

  int max_w = 0;
  rep(i, h) {
    rep(j, w) {
      dp[i][j] = (c[i][j] + 1) % 2;
      max_w |= dp[i][j];
    }
  }

  for (int i = 1; i < h; i++) {
    for (int j = 1; j < w; j++) {
      if (c[i][j]) {
        dp[i][j] = 0;
      } else {
        dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
        max_w = max(max_w, dp[i][j]);
      }
    }
  }

  cout << max_w * max_w << endl;
  return 0;
}