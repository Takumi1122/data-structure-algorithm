#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 153 F - Silver Fox vs Monster
      https://atcoder.jp/contests/abc153/tasks/abc153_f
*/

template <class Abel>
struct BIT {
  const Abel UNITY_SUM = 0;  // to be set
  vector<Abel> dat;

  /* [1, n] */
  BIT(int n) : dat(n + 1, UNITY_SUM) {}
  void init(int n) { dat.assign(n + 1, UNITY_SUM); }

  /* a is 1-indexed */
  inline void add(int a, Abel x) {
    for (int i = a; i < (int)dat.size(); i += i & -i) dat[i] = dat[i] + x;
  }

  /* [1, a], a is 1-indexed */
  inline Abel sum(int a) {
    Abel res = UNITY_SUM;
    for (int i = a; i > 0; i -= i & -i) res = res + dat[i];
    return res;
  }

  /* [a, b), a and b are 1-indexed */
  inline Abel sum(int a, int b) { return sum(b - 1) - sum(a - 1); }

  /* debug */
  void print() {
    for (int i = 1; i < (int)dat.size(); ++i) cout << sum(i, i + 1) << ",";
    cout << endl;
  }
};

int main() {
  int n, d, a;
  cin >> n >> d >> a;
  vector<P> p(n);
  rep(i, n) cin >> p[i].first >> p[i].second;
  sort(p.begin(), p.end());

  ll ans = 0;
  BIT<ll> bit(n + 1);
  rep(i, n) {
    ll x = p[i].first;
    ll h = p[i].second;
    h -= bit.sum(i + 1);
    if (h <= 0) continue;
    ll num = (h + a - 1) / a;
    ans += num;
    ll damage = num * a;
    bit.add(i + 1, damage);
    int rx = min(x + d * 2, 1001001001ll);
    int j = upper_bound(p.begin(), p.end(), P(rx + 1, -1)) - p.begin();
    bit.add(j + 1, -damage);
  }

  cout << ans << endl;
  return 0;
}
