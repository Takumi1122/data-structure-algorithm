#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 個数制限付き部分和問題
// O(n * k)

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  vector<int> m(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> m[i];

  vector<int> dp(k + 1, -1);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= k; j++) {
      if (dp[j] >= 0) {
        dp[j] = m[i];
      } else if (j < a[i] || dp[j - a[i]] <= 0) {
        dp[j] = -1;
      } else {
        dp[j] = dp[j - a[i]] - 1;
      }
    }
  }

  if (dp[k] >= 0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}