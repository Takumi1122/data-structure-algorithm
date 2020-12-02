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
ll dpsum[2005];

int main() {
  int s;
  cin >> s;

  dp[0] = 1;
  dpsum[1] = 1;
  for (int v = 1; v <= s; ++v) {
    if (v - 2 >= 0) {
      dp[v] = dpsum[v - 2];
      dp[v] %= mod;
    }
    dpsum[v + 1] = dpsum[v] + dp[v];
    dpsum[v + 1] %= mod;
  }

  cout << dp[s] % mod << endl;
  return 0;
}