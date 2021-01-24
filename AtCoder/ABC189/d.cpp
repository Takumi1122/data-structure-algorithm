#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 数え上げDP modを取っていない
// 制約 n <= 60 long long型におさまる
// 制約上,bit全探索はできない

/*
    参考リンク
    ABC 189 D - Logical Expression
      https://atcoder.jp/contests/abc189/tasks/abc189_d
*/

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) cin >> s[i];

  // dp[i][j]: xi まで決めたとき yi = j となる場合の数
  vector<vector<ll>> dp(n + 1, vector<ll>(2));
  dp[0][0] = 1;
  dp[0][1] = 1;

  rep(i, n) rep(j, 2) rep(k, 2) {
    int nj = j;
    if (s[i] == "AND") {
      nj &= k;
      dp[i + 1][nj] += dp[i][j];
    } else {
      nj |= k;
      dp[i + 1][nj] += dp[i][j];
    }
  }

  cout << dp[n][1] << endl;
  return 0;
}