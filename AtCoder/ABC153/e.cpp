#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 個数制限なしナップサック 最小化
// in-place

/*
    参考リンク
    ABC 153 E - Crested Ibis vs Monster
      https://atcoder.jp/contests/abc153/tasks/abc153_e
*/

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
const ll INF = 1LL << 60;

int main() {
  int h, n;
  cin >> h >> n;
  vector<int> a(n);
  vector<int> b(n);
  rep(i, n) cin >> a[i] >> b[i];

  vector<ll> dp(h + 1, INF);
  dp[0] = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= h; j++) {
      chmin(dp[min(j + a[i], h)], dp[j] + b[i]);
    }
  }

  cout << dp[h] << endl;
  return 0;
}
