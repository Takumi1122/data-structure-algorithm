#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 178 D - Redistribution
      https://atcoder.jp/contests/abc178/tasks/abc178_d
*/

// dp[v] := 総和がvとなるような数列の個数
const int mod = 1e9 + 7;
ll dp[2005];

int main() {
  int s;
  cin >> s;

  dp[0] = 1;
  for (int v = 1; v <= s; ++v) {
    for (int d = 0; d <= v - 3; ++d) {
      dp[v] += dp[d];
      dp[v] %= mod;
    }
  }

  cout << dp[s] % mod << endl;
  return 0;
}