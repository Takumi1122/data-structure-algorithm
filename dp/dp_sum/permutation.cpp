#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    Educational DP Contest T - Permutation
      https://atcoder.jp/contests/dp/tasks/dp_t
*/

const int mod = 1000000007;
ll dp[3009][3009];

int main() {
  int n;
  string s;
  cin >> n >> s;

  rep(j, n) dp[0][j] = 1;

  rep(i, n - 1) {
    // 累積和
    int sum[3009];
    sum[0] = 0;
    for (int j = 0; j < n - i; j++) sum[j + 1] = (sum[j] + dp[i][j]) % mod;

    if (s[i] == '<') {
      for (int j = 0; j < n - i; j++)
        // 負の mod に気を付ける
        dp[i + 1][j] = (sum[n - i] - sum[j + 1] + mod) % mod;
    }
    if (s[i] == '>') {
      for (int j = 0; j < n - i; j++) dp[i + 1][j] = sum[j + 1];
    }
  }

  cout << dp[n - 1][0] << endl;

  return 0;
}