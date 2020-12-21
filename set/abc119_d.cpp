#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// set + 二分探索
// 前後の値を取得

/*
    参考リンク
    ABC 119 D - Lazy Faith
      https://atcoder.jp/contests/abc119/tasks/abc119_d
*/

int main() {
  int a, b, q;
  cin >> a >> b >> q;
  set<ll> s;
  set<ll> t;
  rep(i, a) {
    ll si;
    cin >> si;
    s.insert(si);
  }
  s.insert(1e15);
  s.insert(-1e15);
  rep(i, b) {
    ll ti;
    cin >> ti;
    t.insert(ti);
  }
  t.insert(1e15);
  t.insert(-1e15);

  rep(i, q) {
    ll x;
    cin >> x;
    auto sx = s.lower_bound(x);
    ll s1 = *sx;
    sx--;
    ll s2 = *sx;
    auto tx = t.lower_bound(x);
    ll t1 = *tx;
    tx--;
    ll t2 = *tx;

    ll ans = min(abs(x - max(s1, t1)), abs(x - min(s2, t2)));
    ans = min(ans, abs(x - s1) + abs(s1 - t2));
    ans = min(ans, abs(x - s2) + abs(s2 - t1));
    ans = min(ans, abs(x - t1) + abs(t1 - s2));
    ans = min(ans, abs(x - t2) + abs(t2 - s1));
    cout << ans << endl;
  }
  return 0;
}