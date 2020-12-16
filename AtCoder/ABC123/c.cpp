#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// ボトルネックに着目

/*
    参考リンク
    ABC 123 C - Five Transportations
      https://atcoder.jp/contests/abc123/tasks/abc123_c
*/

int main() {
  ll n;
  cin >> n;
  vector<ll> a(5);
  rep(i, 5) cin >> a[i];

  ll mn = 1e18;
  rep(i, 5) mn = min(mn, a[i]);
  ll ans = 5 + (n + mn - 1) / mn - 1;

  cout << ans << endl;
  return 0;
}