#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int n, m;
  int a[100];
  int c[100];
  int dp[100001];
  int cnt;
  // ifstream cin( "test.txt" );
  while (1) {
    // 入力
    cin >> n >> m;
    if (!(n | m)) return 0;

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> c[i];

    // 計算
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= m; j++) {
        if (dp[j] >= 0) {
          dp[j] = c[i];
        } else if (j - a[i] >= 0 && dp[j - a[i]] > 0) {
          dp[j] = dp[j - a[i]] - 1;
        } else {
          dp[j] = -1;
        }
      }
    }
    cnt = 0;
    for (int j = 1; j <= m; j++) {
      if (dp[j] >= 0) cnt++;
    }
    // 出力
    cout << cnt << endl;
  }
}