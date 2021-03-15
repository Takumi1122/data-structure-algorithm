#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// ゲームは最終状態から遡る

/*
    参考リンク
    ABC 195 E - Lucky 7 Battle
      https://atcoder.jp/contests/abc195/tasks/abc195_e
*/

int main() {
  int n;
  string s, x;
  cin >> n >> s >> x;

  // dp[i][j]: i文字目まで決まっていて、mod7がjのときの勝敗
  vector<vector<int>> dp(n + 1, vector<int>(7));
  dp[n][0] = 1;  // Takahashi win
  int ten = 1;

  for (int i = n - 1; i >= 0; --i) {
    rep(j, 7) {
      int nj = (j + ten * (s[i] - '0')) % 7;
      if (x[i] == 'T') {
        dp[i][j] = dp[i + 1][j] | dp[i + 1][nj];
      } else {
        dp[i][j] = dp[i + 1][j] & dp[i + 1][nj];
      }
    }

    ten = (ten * 10) % 7;
  }

  if (dp[0][0] == 1)
    cout << "Takahashi" << endl;
  else
    cout << "Aoki" << endl;
  return 0;
}