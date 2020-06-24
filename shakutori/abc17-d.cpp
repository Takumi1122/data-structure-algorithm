#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MOD = 1000000007;
int dp[110000];
int sum[110000];

int main() {
  /* 入力 */
  int n, m;
  cin >> n >> m;
  vector<int> f(n);
  rep(i, n) cin >> f[i], --f[i];

  /* しゃくとり法 */
  vector<int> fnum(m, 0);   // 区間に種類 i が何個あるか
  vector<int> L(n + 1, 0);  // 各 i に対するしゃくとり法の区間
  int left = 0;
  rep(right, n) {
    fnum[f[right]]++;
    while (left < right && fnum[f[right]] > 1) {
      --fnum[f[left]];
      ++left;
    }
    L[right + 1] = left;
  }

  /* 累積和で高速化した DP */
  dp[0] = 1;
  sum[0] = 0;
  sum[1] = 1;
  for (int i = 1; i <= n; ++i) {
    dp[i] = (sum[i] - sum[L[i]] + MOD) % MOD;  // DP
    sum[i + 1] = (sum[i] + dp[i]) % MOD;       // 累積
  }

  cout << dp[n] << endl;
}