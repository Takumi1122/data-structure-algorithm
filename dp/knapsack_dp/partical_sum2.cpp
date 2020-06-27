#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// o(n * A) 部分和数え上げ問題

const int MOD = 1000000009;

// 入力
int n, A;
int a[110];

// DPテーブル
int dp[110][10010];

int main() {
  cin >> n >> A;
  rep(i, n) cin >> a[i];

  memset(dp, 0, sizeof(dp));  // 一旦すべて 0 に
  dp[0][0] = 1;               // dp[0][0] だけ 1 に

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= A; ++j) {
      (dp[i + 1][j] += dp[i][j]) %= MOD;
      if (j >= a[i]) (dp[i + 1][j] += dp[i][j - a[i]]) %= MOD;
    }
  }

  cout << dp[n][A] << endl;
}