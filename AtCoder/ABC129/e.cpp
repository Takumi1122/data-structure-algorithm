#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// どの桁についてもaとbがともに1になることはないこと

/*
    参考リンク
    ABC 129 E - Sum Equals Xor
      https://atcoder.jp/contests/abc129/tasks/abc129_e
*/

const int mod = 1000000007;
int dp[100005][2];

int main() {
  string s;
  cin >> s;
  int n = s.size();

  dp[0][0] = 1;
  rep(i, n) {
    {  // a+b = 0 (a,b) = (0,0)
      if (s[i] == '0') {
        (dp[i + 1][0] += dp[i][0]) %= mod;
        (dp[i + 1][1] += dp[i][1]) %= mod;
      } else {
        dp[i + 1][1] += (dp[i][0] + dp[i][1]) % mod;
      }
    }
    {  // a+b = 1 (a,b) = (0,1),(1,0)
      if (s[i] == '0') {
        (dp[i + 1][1] += dp[i][1] * 2 % mod) %= mod;
      } else {
        (dp[i + 1][0] += dp[i][0] * 2 % mod) %= mod;
        (dp[i + 1][1] += dp[i][1] * 2 % mod) %= mod;
      }
    }
  }

  int ans = (dp[n][0] + dp[n][1]) % mod;
  cout << ans << endl;
  return 0;
}
