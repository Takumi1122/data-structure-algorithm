#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC155 E – Payment
      https://atcoder.jp/contests/abc155/tasks/abc155_e
*/

const int INF = 1001001001;

// dp[i][j]: 下からi桁目まで決めて、繰り下がりがjのときの最小値
// i: 0~N j: 0~1
// 筆算をしているので、下の桁から見ていくのがおすすめ
int dp[1000005][2];

int main() {
  string s;
  cin >> s;

  // 下の桁から見ていくため
  reverse(s.begin(), s.end());
  s += '0';
  int n = s.size();

  rep(i, n + 1) rep(j, 2) dp[i][j] = INF;
  dp[0][0] = 0;
  rep(i, n) rep(j, 2) {
    int x = s[i] - '0';

    // ai - ni = bi
    // 繰り下がりの場合 ni++
    x += j;

    rep(a, 10) {
      int ni = i + 1, nj = 0;
      int b = a - x;
      if (b < 0) {
        nj = 1;
        b += 10;
      }
      dp[ni][nj] = min(dp[ni][nj], dp[i][j] + a + b);
    }
  }

  int ans = dp[n][0];
  cout << ans << endl;
  return 0;
}
