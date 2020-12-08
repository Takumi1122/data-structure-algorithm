#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define chmax(x, y) x = max(x, y)

/*
    偶数の場合: |○|×|○| 仕切りから一箇所選ぶ
    奇数の場合: |○|×|○| 仕切りから二箇所選ぶ
*/

/*
    参考リンク
    ABC 162 F - Select Half
      https://atcoder.jp/contests/abc162/tasks/abc162_f
*/

const ll INF = 1e18;

// dp[i][j]: i個目まで見て,j個余分な×を入れたときのmax
ll dp[200005][4];

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  // 何個余分な×を入れることができるか
  int k = 1 + n % 2;
  rep(i, n + 1) rep(j, k + 1) dp[i][j] = -INF;
  dp[0][0] = 0;
  rep(i, n) {
    rep(j, k + 1) {
      chmax(dp[i + 1][j + 1], dp[i][j]);
      ll now = dp[i][j];
      if ((i + j) % 2 == 0) now += a[i];
      chmax(dp[i + 1][j], now);
    }
  }

  ll ans = dp[n][k];
  cout << ans << endl;
  return 0;
}