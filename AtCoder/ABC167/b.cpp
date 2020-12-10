#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll a, b, c, k;
  cin >> a >> b >> c >> k;

  ll mx;
  if (a >= k) {
    mx = k;
    cout << mx << endl;
    return 0;
  } else {
    k -= a;
  }

  if (b >= k) {
    cout << a << endl;
    return 0;
  } else {
    k -= b;
  }

  if (c >= k) {
    cout << a - k << endl;
    return 0;
  } else {
    cout << a - c << endl;
    return 0;
  }
  return 0;
}