#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

// 累積和の累積和 s
// 累積和 b

/*
    参考リンク
    ABC 182 D - Wandering
      https://atcoder.jp/contests/abc182/tasks/abc182_d
*/

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  ll ans = 0;
  // 累積和の累積和 s
  // 累積和 b
  ll s = 0, b = 0;
  ll max_b = 0;
  rep(i, n) {
    b += a[i];
    max_b = max(max_b, b);
    ans = max(ans, s + max_b);
    s += b;
  }

  cout << ans << endl;
  return 0;
}