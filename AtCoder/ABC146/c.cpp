#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll a, b, x;
  cin >> a >> b >> x;
  ll l = 0, r = 1e9 + 1;
  while (l + 1 < r) {
    ll t = (l + r) / 2;
    ll keta = t;
    ll d = 0;
    while (keta > 0) {
      d++;
      keta /= 10;
    }
    ll sum = a * t + b * d;
    if (x >= sum) {
      l = t;
    } else {
      r = t;
    }
  }
  cout << l << endl;
  return 0;
}