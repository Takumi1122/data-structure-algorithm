#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 数え上げDP

/*
    参考リンク
    Educational DP Contest H - Grid 1
      https://atcoder.jp/contests/dp/tasks/dp_h
*/

const int mod = 1000000007;
int dp[1100][1100];

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  rep(i, h) cin >> a[i];

  dp[0][0] = 1;
  rep(i, h) rep(j, w) {
    if (i < h - 1 && a[i + 1][j] == '.') add(dp[i + 1][j], dp[i][j]);
    if (j < w - 1 && a[i][j + 1] == '.') add(dp[i][j + 1], dp[i][j]);
  }
  cout << dp[h - 1][w - 1] << endl;
  return 0;
}