#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 配るDP

/*
    参考リンク
    ABC 99 C - Strange Bank
      https://atcoder.jp/contests/abc099/tasks/abc099_c
*/

const int MAX_N = 110000;
int dp[MAX_N];

int main() {
  int n;
  cin >> n;

  rep(i, MAX_N) dp[i] = n;
  dp[0] = 0;

  // 配る DP --- dp[n]から遷移を出して行く
  for (int i = 0; i < n; ++i) {
    for (int pow6 = 1; i + pow6 <= n; pow6 *= 6) {
      dp[i + pow6] = min(dp[i + pow6], dp[i] + 1);
    }
    for (int pow9 = 1; i + pow9 <= n; pow9 *= 9) {
      dp[i + pow9] = min(dp[i + pow9], dp[i] + 1);
    }
  }

  cout << dp[n] << endl;
  return 0;
}