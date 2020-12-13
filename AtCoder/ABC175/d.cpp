#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 周期性 1~K回の移動

/*
    参考リンク
    ABC 175 D - Moving Piece
      https://atcoder.jp/contests/abc175/tasks/abc175_d
*/

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> p(n), c(n);
  rep(i, n) cin >> p[i];
  rep(i, n) cin >> c[i];
  rep(i, n) p[i]--;

  ll ans = -1e18;
  rep(si, n) {
    int x = si;
    vector<int> s;
    // 1周のスコアの合計
    ll tot = 0;
    while (1) {
      x = p[x];
      s.push_back(c[x]);
      tot += c[x];
      if (x == si) break;
    }
    int l = s.size();
    ll t = 0;
    // tot < 0: 周期の前の方で切る
    // tot > 0: 周期の後ろの方で切る
    rep(i, l) {
      t += s[i];
      if (i + 1 > k) break;
      ll now = t;
      if (tot > 0) {
        ll e = (k - (i + 1)) / l;
        now += tot * e;
      }
      ans = max(ans, now);
    }
  }

  cout << ans << endl;
  return 0;
}
