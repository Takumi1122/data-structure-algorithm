#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 区間kについての全探索

/*
    参考リンク
    ABC 107 C - Candles
      https://atcoder.jp/contests/abc107/tasks/arc101_a
*/

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> x(n);
  rep(i, n) cin >> x[i];

  ll ans = 1e9;
  for (int i = 0; i + k - 1 < n; i++) {
    ll left = x[i];
    ll right = x[i + k - 1];
    ans = min(ans, min(abs(left), abs(right)) + right - left);
  }

  cout << ans << endl;
  return 0;
}