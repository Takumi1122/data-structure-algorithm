#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n;
  cin >> n;

  ll res = 1e16;  // 十分大きい値で初期化
  for (ll a = 1; a * a <= n; ++a) {
    if (n % a == 0) {
      ll b = n / a;
      ll sum = a + b;
      res = min(res, sum);
    }
  }
  cout << res - 2 << endl;
  return 0;
}