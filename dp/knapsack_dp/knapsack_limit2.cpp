#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 個数制限付きナップサック問題 O(n * W * log(m))

/*
    参考リンク
    AIZU ONLINE JUDGE
      https://onlinejudge.u-aizu.ac.jp/problems/DPL_1_G
*/

int main() {
  int n, W;
  cin >> n >> W;
  vector<int> v(n), w(n), m(n);
  rep(i, n) cin >> v[i] >> w[i] >> m[i];

  vector<int> dp(W + 1);
  rep(i, n) {
    int num = m[i];
    for (int k = 1; num > 0; k <<= 1) {
      int mul = min(k, num);
      for (int j = W; j >= w[i] * mul; j--) {
        dp[j] = max(dp[j], dp[j - w[i] * mul] + v[i] * mul);
      }
      num -= mul;
    }
  }

  cout << dp[W] << endl;
  return 0;
}