#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    Educational DP Contest M - Candies
      https://atcoder.jp/contests/dp/tasks/dp_m
*/

const int mod = 1000000007;
int dp[110][100010];

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  dp[0][0] = 1;

  rep(i, n) {
    // 累積和を取る
    int sum[100010];
    sum[0] = 0;
    for (int j = 0; j <= k; j++) sum[j + 1] = (sum[j] + dp[i][j]) % mod;

    for (int j = 0; j <= k; j++)
      // 負の mod に気を付ける
      dp[i + 1][j] = (sum[j + 1] - sum[max(0, j - a[i])] + mod) % mod;
  }

  cout << dp[n][k] << endl;

  return 0;
}