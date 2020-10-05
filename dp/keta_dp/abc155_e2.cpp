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

/*
    桁DPで解ける問題
    ・Nが非常に大きく64bitで収まらない
    ・「N以下の整数」について条件に合うものを数える
*/

// dp[i][over] :
// 上位i桁目までの支払い方で、使用する紙幣の枚数が最小となる時の枚数
// over = trueの時は、i桁目を1枚余分に支払って、下の桁でお釣りをもらう予定
ll dp[1000005][2];

int main() {
  string N;
  cin >> N;

  dp[0][1] = 1;
  rep(i, (int)N.size()) {
    int now = (int)(N[i] - '0');
    dp[i + 1][0] = min(dp[i][0] + now, dp[i][1] + (10 - now));
    dp[i + 1][1] = min(dp[i][0] + now + 1, dp[i][1] + (10 - now - 1));
  }

  cout << dp[N.size()][0] << endl;
  return 0;
}