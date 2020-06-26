#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int dp[105][4][2];

int main() {
  string s;
  cin >> s;
  int n = s.size();
  int K;
  cin >> K;
  dp[0][0][0] = 1;
  rep(i, n) rep(j, 4) rep(k, 2) {
    int nd = s[i] - '0';
    rep(d, 10) {
      int ni = i + 1, nj = j, nk = k;
      if (d != 0) nj++;
      if (nj > K) continue;
      if (k == 0) {
        if (d > nd) continue;
        if (d < nd) nk = 1;
      }
      dp[ni][nj][nk] += dp[i][j][k];
    }
  }
  int ans = dp[n][K][0] + dp[n][K][1];
  cout << ans << endl;
  return 0;
}
