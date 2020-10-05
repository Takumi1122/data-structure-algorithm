#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC154 E – Almost Everywhere Zero
      https://atcoder.jp/contests/abc154/tasks/abc154_e
*/

/*
    桁DPで解ける問題
    ・Nが非常に大きく64bitで収まらない
    ・「N以下の整数」について条件に合うものを数える
*/

// dp[i][j][smaller] :
// i桁目までを決めた時、0でない数字がj回出現する数はいくつあるか。
// smallerがtrueならNより小さい場合を考え、smallerがfalseならNと同じ場合を考える。
int dp[105][4][2];

int main() {
  string s;
  cin >> s;
  int n = s.size();
  int K;
  cin >> K;

  dp[0][0][0] = 1;
  rep(i, n) rep(j, 4) rep(k, 2) {
    int nd = s[i] - '0';
    rep(d, 10) {
      int ni = i + 1, nj = j, nk = k;
      if (d != 0) nj++;
      if (nj > K) continue;
      // k: i桁目までについて、与えられた数字Nより小さいかどうか
      if (k == 0) {
        if (d > nd) continue;
        if (d < nd) nk = 1;
      }
      dp[ni][nj][nk] += dp[i][j][k];
    }
  }

  int ans = dp[n][K][0] + dp[n][K][1];
  cout << ans << endl;
  return 0;
}
