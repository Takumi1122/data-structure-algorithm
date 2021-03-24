#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 関数の合成
// f(x) = min(c,max(b,x+a))

/*
    参考リンク
    ABC 196 E - Filters
      https://atcoder.jp/contests/abc196/tasks/abc196_e
*/

const ll INF = 1ll << 60;

int main() {
  int n, q;
  cin >> n;

  ll s = 0;
  ll l = -INF, r = INF;
  rep(i, n) {
    ll a, t;
    cin >> a >> t;
    if (t == 1) {  // +
      s += a;
      l += a;
      r += a;
    } else if (t == 2) {  // max
      l = max(l, a);
      r = max(r, a);
    } else {  // min
      l = min(l, a);
      r = min(r, a);
    }
  }

  cin >> q;
  rep(qi, q) {
    ll x;
    cin >> x;
    ll ans = x + s;
    if (ans < l) ans = l;
    if (ans > r) ans = r;
    cout << ans << endl;
  }
  return 0;
}