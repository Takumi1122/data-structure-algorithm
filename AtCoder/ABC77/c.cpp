#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// a.begin() => 0
// a.end() => a.size()

/*
    参考リンク
    ABC 77 C - Snuke Festival
      https://atcoder.jp/contests/abc077/tasks/arc084_a
*/

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  rep(i, n) cin >> c[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());

  ll ans = 0;
  rep(i, n) {
    // b[i]より小さい値の個数
    ll x = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
    // b[i]より大きい値の個数
    ll y = c.end() - upper_bound(c.begin(), c.end(), b[i]);
    ans += x * y;
  }

  cout << ans << endl;
  return 0;
}