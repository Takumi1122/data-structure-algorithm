#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

/*
    参考リンク
    ABC 62 C - Chocolate Bar
      https://atcoder.jp/contests/abc062/tasks/arc074_a
*/

int main() {
  ll h, w;
  cin >> h >> w;

  ll ans = 1e18;
  // 横に1本、縦に1本で分割
  for (ll i = 1; i < h; i++) {
    ll sa = i * w;
    ll sb = (h - i) * (w / 2);
    ll sc = (h - i) * (w - w / 2);
    ll mx = max({sa, sb, sc});
    ll mn = min({sa, sb, sc});
    ans = min(ans, mx - mn);
  }
  // 横に2本で分割
  for (ll i = 1; i < h - 1; i++) {
    ll sa = i * w;
    ll sb = (h - i) / 2 * w;
    ll sc = ((h - i) - (h - i) / 2) * w;
    ll mx = max({sa, sb, sc});
    ll mn = min({sa, sb, sc});
    ans = min(ans, mx - mn);
  }
  // 縦に1本、横に1本で分割
  for (ll i = 1; i < w; i++) {
    ll sa = i * h;
    ll sb = (w - i) * (h / 2);
    ll sc = (w - i) * (h - h / 2);
    ll mx = max({sa, sb, sc});
    ll mn = min({sa, sb, sc});
    ans = min(ans, mx - mn);
  }
  // 縦に2本で分割
  for (ll i = 1; i < w - 1; i++) {
    ll sa = i * h;
    ll sb = (w - i) / 2 * h;
    ll sc = ((w - i) - (w - i) / 2) * h;
    ll mx = max({sa, sb, sc});
    ll mn = min({sa, sb, sc});
    ans = min(ans, mx - mn);
  }

  cout << ans << endl;
  return 0;
}