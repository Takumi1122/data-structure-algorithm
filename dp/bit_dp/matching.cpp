#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    Educational DP Contest O - Matching
      https://atcoder.jp/contests/dp/tasks/dp_o
*/

const int mod = 1000000007;

// 男性i−1までの相手を決め、すでにペアに使った女性の集合がSである場合の数
bool a[21][21];
int dp[1 << 21];

int main() {
  int n;
  cin >> n;
  rep(i, n) rep(j, n) cin >> a[i][j];

  dp[0] = 1;
  for (int s = 1; s < 1 << n; s++) {
    int i = __builtin_popcount(s);
    rep(j, n) {
      if (s >> j & 1 && a[i - 1][j] == 1) {
        dp[s] += dp[s ^ (1 << j)];
        dp[s] %= mod;
      }
    }
  }

  cout << dp[(1 << n) - 1] << endl;
  return 0;
}