#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    Educational DP Contest S - Digit Sum
      https://atcoder.jp/contests/dp/tasks/dp_s
*/

/*
    桁DPで解ける問題
    ・Nが非常に大きく64bitで収まらない
    ・「N以下の整数」について条件に合うものを数える
*/

const int mod = 1e9 + 7;

// dp[i][smaller][j] : i桁目までの各桁の数の和が(mod d)でjとなる数
// smallerがtrueならNより小さい場合を考え、smallerがfalseならNと同じ場合を考える
ll dp[10005][2][105];

int main() {
  string N;
  int d;
  cin >> N >> d;
  int n = N.size();
  dp[0][0][0] = 1;
  rep(i, n) {
    rep(j, d) {
      // i桁目まででNより小さいならi+1桁目は何でも良い
      rep(k, 10) {
        dp[i + 1][1][(j + k) % d] += dp[i][1][j];
        dp[i + 1][1][(j + k) % d] %= mod;
      }

      int ni = (N[i] - '0');
      // i桁目までNと同じで、i+1桁目はNより小さい数の時
      rep(k, ni) {
        dp[i + 1][1][(j + k) % d] += dp[i][0][j];
        dp[i + 1][1][(j + k) % d] %= mod;
      }

      //  i桁目までNと同じで、i+1桁目もNと同じ数の時
      dp[i + 1][0][(j + ni) % d] = dp[i][0][j];
      dp[i + 1][0][(j + ni) % d] %= mod;
    }
  }

  cout << (dp[n][0][0] + dp[n][1][0] - 1 + mod) % mod << endl;
  return 0;
}