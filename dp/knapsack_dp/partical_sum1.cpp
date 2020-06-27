#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// o(n * A) 部分和問題

// 入力
int n, A;
int a[110];

// DPテーブル
bool dp[110][10010];

int main() {
  cin >> n >> A;
  rep(i, n) cin >> a[i];

  memset(dp, 0, sizeof(dp));  // 一旦すべて false に
  dp[0][0] = true;            // dp[0][0] だけ true に

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= A; ++j) {
      dp[i + 1][j] |= dp[i][j];
      if (j >= a[i]) dp[i + 1][j] |= dp[i][j - a[i]];
    }
  }

  if (dp[n][A])
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}