#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 累積和によるDP高速化

/*
    参考リンク
    Typical DP Contest F - 準急
      https://atcoder.jp/contests/tdpc/tasks/tdpc_semiexp
*/

ll dp[1234567];   // dp[n] = n駅まできて、現在0連続停車
ll sum[1234567];  // sum[n] = n駅まできて、現在1～K-1連続停車
ll MOD = 1000000007;

int main() {
  int n, k;
  cin >> n >> k;

  dp[0] = 1;
  sum[1] = 1;
  for (int i = 1; i <= n - 1; ++i) {
    dp[i + 1] = sum[i] + dp[i];
    dp[i + 1] %= MOD;
    sum[i + 1] = sum[i] + dp[i];
    sum[i + 1] %= MOD;
    if (i + 1 >= k) {
      sum[i + 1] = sum[i + 1] - dp[i + 1 - k] + MOD;
      sum[i + 1] %= MOD;
    }
  }

  cout << sum[n] << endl;

  return 0;
}