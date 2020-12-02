#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 127 D - Integer Cards
      https://atcoder.jp/contests/abc127/tasks/abc127_d
*/

int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  vector<ll> b(m);
  vector<ll> c(m);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());
  rep(i, m) cin >> b[i] >> c[i];

  vector<int> id(m);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](int i, int j) { return c[i] > c[j]; });

  ll ans = 0;
  ll k = 0;
  for (auto i : id) {
    rep(j, b[i]) {
      if (k >= n) break;
      ans += max(a[k++], c[i]);
    }
  }
  for (int i = k; i < n; ++i) ans += a[i];

  cout << ans << endl;
  return 0;
}