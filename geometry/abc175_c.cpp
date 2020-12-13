#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 175 C - Walking Takahashi
      https://atcoder.jp/contests/abc175/tasks/abc175_c
*/

int main() {
  ll x, k, d;
  cin >> x >> k >> d;

  x = abs(x);
  ll ans;

  if (x / d > k) {
    ans = x - d * k;
  } else {
    ll e = x / d;
    k -= e;
    x -= e * d;
    if (k % 2 == 1) x = abs(x - d);
    ans = x;
  }

  cout << ans << endl;
  return 0;
}
