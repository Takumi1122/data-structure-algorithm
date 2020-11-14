#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 桁DPの応用
// 整数を「10倍してaを足す」で捉える
// なぜ13で割るのかを考えてみると、動的計画法に気が付きやすい

/*
    参考リンク
    ABC 135 D - Digits Parade
      https://atcoder.jp/contests/abc135/tasks/abc135_d
*/

const int mod = 1000000007;
void add(ll &a, ll b) {
  a += b;
  if (a >= mod) a %= mod;
}

int main() {
  string s;
  cin >> s;
  vector<vector<ll>> dp(s.size() + 1, vector<ll>(13, 0));
  dp[0][0] = 1;
  rep(i, s.size()) {
    rep(j, 13) {
      if (s[i] == '?') {
        rep(k, 10) add(dp[i + 1][(j * 10 + k) % 13], dp[i][j]);
      } else {
        int k = s[i] - '0';
        add(dp[i + 1][(j * 10 + k) % 13], dp[i][j]);
      }
    }
  }

  cout << dp[s.size()][5] << endl;
  return 0;
}