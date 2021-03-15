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

  // dp[j]: mod7がjのときの勝敗
  vector<int> dp(7);
  dp[0] = 1;  // Takahashi win
  int ten = 1;

  for (int i = n - 1; i >= 0; --i) {
    vector<int> old(7);
    swap(dp, old);
    rep(j, 7) {
      int nj = (j + ten * (s[i] - '0')) % 7;
      if (x[i] == 'T') {
        dp[j] = old[j] | old[nj];
      } else {
        dp[j] = old[j] & old[nj];
      }
    }

    ten = (ten * 10) % 7;
  }

  if (dp[0] == 1)
    cout << "Takahashi" << endl;
  else
    cout << "Aoki" << endl;
  return 0;
}