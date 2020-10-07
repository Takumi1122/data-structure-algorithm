#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

// 解を仮定し可能かを二分探索で判定
// 最小値を求める

/*
    参考リンク
    ABC 144 E - Gluttony
      https://atcoder.jp/contests/abc144/tasks/abc144_e
*/

int main() {
  int n;
  ll k;
  cin >> n >> k;
  vector<int> a(n);
  vector<int> f(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> f[i];

  sort(a.begin(), a.end());
  sort(f.rbegin(), f.rend());

  // 解を決め打ち
  ll l = -1, r = 1e12;
  while (l + 1 < r) {
    ll c = (l + r) / 2;

    //　解を決め打ちしたときの条件
    bool ok = [&] {
      ll s = 0;
      rep(i, n) { s += max(0ll, a[i] - c / f[i]); }
      return s <= k;
    }();

    if (ok)
      r = c;
    else
      l = c;
  }

  cout << r << endl;
  return 0;
}
