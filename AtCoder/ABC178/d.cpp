#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int mod = 1e9 + 7;
ll dp[2005][2005];

int main() {
  int s;
  cin >> s;

  dp[0][0] = 1;
  for (int i = 0; i < s / 3; i++) {
    for (int j = i * 3; j <= s - 3; j++) {
      for (int k = j + 3; k <= s; k++) {
        dp[i + 1][k] += dp[i][j];
        dp[i + 1][k] %= mod;
      }
    }
  }

  int ans = 0;
  rep(i, s / 3) {
    ans += dp[i + 1][s];
    ans %= mod;
  }

  cout << ans << endl;
  return 0;
}