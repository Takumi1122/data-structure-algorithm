#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    Educational DP Contest L - Deque
      https://atcoder.jp/contests/dp/tasks/dp_l
*/

// 元の数列から連続する区間を抜き出した状態の局面から出発して、
// 双方最善を尽くしたときのX−Yの値
ll dp[3100][3100];

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  rep(i, n) dp[i][i] = 0;

  for (int len = 1; len <= n; ++len) {
    for (int i = 0; i + len <= n; ++i) {
      int j = i + len;

      // 先手番
      if ((n - len) % 2 == 0)
        dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j - 1]);
      // 後手番
      else
        dp[i][j] = min(dp[i + 1][j] - a[i], dp[i][j - 1] - a[j - 1]);
    }
  }

  cout << dp[0][n] << endl;
  return 0;
}