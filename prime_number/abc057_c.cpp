#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int calc_digit(ll n) {
  int res = 0;
  while (n) {
    ++res;
    n /= 10;
  }
  return res;
}

int main() {
  ll n;
  cin >> n;
  int res = (1 << 29);  // 十分大きい値で初期化
  for (ll a = 1; a * a <= n; ++a) {
    if (n % a == 0) {
      ll b = n / a;
      int f = max(calc_digit(a), calc_digit(b));
      res = min(res, f);
    }
  }
  cout << res << endl;
}