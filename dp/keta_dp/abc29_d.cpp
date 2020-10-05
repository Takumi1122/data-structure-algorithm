#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    [AtCoder] ABC029 D – 1
      https://atcoder.jp/contests/abc029/tasks/abc029_d
*/

/*
    桁DPで解ける問題
    ・Nが非常に大きく64bitで収まらない
    ・「N以下の整数」について条件に合うものを数える
*/

// dp[i][smaller][j] : i桁目までを決めた時、1がj回出現する数がいくつあるか。
// smallerがtrueならNより小さい場合を考え、smallerがfalseならNと同じ場合を考える。
ll dp[11][2][11];

int main() {
  string N;
  cin >> N;
  int n = N.size();
  dp[0][0][0] = 1;
  rep(i, n) {
    rep(j, 10) {
      // i桁目まででNより小さいならi+1桁目は何でも良い
      dp[i + 1][1][j] += dp[i][1][j] * 9;  // i+1桁目が1以外
      dp[i + 1][1][j + 1] += dp[i][1][j];  // i+1桁目が1

      int ni = (N[i] - '0');
      // i桁目までNと同じで、i+1桁目はNより小さい数の時
      if (ni > 1) {
        // i+1桁目が0~ni-1のうちの1以外
        dp[i + 1][1][j] += dp[i][0][j] * (ni - 1);
        dp[i + 1][1][j + 1] += dp[i][0][j];  // i+1桁目が1
      } else if (ni == 1) {
        dp[i + 1][1][j] += dp[i][0][j];  // i+1桁目が0
      }

      //  i桁目までNと同じで、i+1桁目もNと同じ数の時
      if (ni == 1) {
        dp[i + 1][0][j + 1] = dp[i][0][j];  // i+1桁目が1
      } else {
        dp[i + 1][0][j] = dp[i][0][j];  // i+1桁目が1以外
      }
    }
  }

  ll ans = 0;
  rep(j, 10) ans += (dp[n][0][j] + dp[n][1][j]) * j;
  cout << ans << endl;
  return 0;
}