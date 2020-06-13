#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

const int D = 80 * 160 + 10;
const int D2 = D * 2;
typedef bitset<D2> bs;

int a[100][100];
bs dp[90][90];

int main() {
  int h, w;
  cin >> h >> w;
  rep(i, h) rep(j, w) {
    int x;
    cin >> x;
    a[i][j] = x;
  }
  rep(i, h) rep(j, w) {
    int x;
    cin >> x;
    a[i][j] = abs(x - a[i][j]);
  }

  dp[0][0][D - a[0][0]] = 1;
  dp[0][0][D + a[0][0]] = 1;
  rep(i, h) rep(j, w) {
    if (i) {
      dp[i][j] |= dp[i - 1][j] << a[i][j];
      dp[i][j] |= dp[i - 1][j] >> a[i][j];
    }
    if (j) {
      dp[i][j] |= dp[i][j - 1] << a[i][j];
      dp[i][j] |= dp[i][j - 1] >> a[i][j];
    }
  }
  int ans = D2;
  rep(i, D2) if (dp[h - 1][w - 1][i]) { ans = min(ans, abs(i - D)); }
  cout << ans << endl;
  return 0;
}
