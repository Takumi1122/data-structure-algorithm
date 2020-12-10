#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// floor(a/b) = (a - a % b) / b 床関数
// (a * x) % mod = a * (x % mod) % mod
// x = pb + q (0<= q < b)

// 周期性に着目

/*
    参考リンク
    ABC 165 D - Floor Function
      https://atcoder.jp/contests/abc165/tasks/abc165_d
*/

int main() {
  ll a, b, n;
  cin >> a >> b >> n;

  ll x = n;
  if (n >= b - 1) x = b - 1;
  ll ans = a * x / b - a * (x / b);

  cout << ans << endl;
  return 0;
}
