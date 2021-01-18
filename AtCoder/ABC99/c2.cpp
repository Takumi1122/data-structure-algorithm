#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 貰うDP

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

  // 貰う DP --- dp[i]に遷移を集める
  for (int i = 1; i <= n; ++i) {
    for (int pow6 = 1; pow6 <= i; pow6 *= 6) {
      dp[i] = min(dp[i], dp[i - pow6] + 1);
    }
    for (int pow9 = 1; pow9 <= i; pow9 *= 9) {
      dp[i] = min(dp[i], dp[i - pow9] + 1);
    }
  }

  cout << dp[n] << endl;
  return 0;
}