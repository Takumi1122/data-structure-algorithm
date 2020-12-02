#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 178 C - Ubiquity
      https://atcoder.jp/contests/abc178/tasks/abc178_c
*/

const int mod = 1e9 + 7;
ll dp[1000100][2][2];

int main() {
  int n;
  cin >> n;
  dp[0][0][0] = 1;
  rep(i, n) {
    dp[i + 1][0][0] += 8 * dp[i][0][0];
    dp[i + 1][0][0] %= mod;

    dp[i + 1][1][0] += dp[i][0][0];
    dp[i + 1][1][0] += 9 * dp[i][1][0];
    dp[i + 1][1][0] %= mod;

    dp[i + 1][0][1] += dp[i][0][0];
    dp[i + 1][0][1] += 9 * dp[i][0][1];
    dp[i + 1][0][1] %= mod;

    dp[i + 1][1][1] += dp[i][1][0];
    dp[i + 1][1][1] += dp[i][0][1];
    dp[i + 1][1][1] += 10 * dp[i][1][1];
    dp[i + 1][1][1] %= mod;
  }

  cout << dp[n][1][1] % mod << endl;
  return 0;
}