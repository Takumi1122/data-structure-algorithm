#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int mod = 1e9 + 7;

int main() {
  string s;
  cin >> s;
  vector<vector<ll>> dp(s.size() + 1, vector<ll>(13, 0));
  dp[0][0] = 1;

  reverse(s.begin(), s.end());
  int num = 1;

  rep(i, s.size()) {
    if (s[i] == '?') {
      rep(j, 10) {
        rep(k, 13) {
          int index = (k + j * num) % 13;
          dp[i + 1][index] += dp[i][k];
          dp[i + 1][index] %= mod;
        }
      }
    } else {
      rep(k, 13) {
        int j = (s[i] - '0');
        int index = (k + j * num) % 13;
        dp[i + 1][index] += dp[i][k];
        dp[i + 1][index] %= mod;
      }
    }
    num *= 10;
    num %= 13;
  }
  cout << dp[s.size()][5] << endl;
  return 0;
}