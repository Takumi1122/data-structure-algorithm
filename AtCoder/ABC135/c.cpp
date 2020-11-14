#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n + 1);
  vector<ll> b(n);
  rep(i, n + 1) cin >> a[i];
  rep(i, n) cin >> b[i];
  ll ans = 0;
  ll pre = 0;
  rep(i, n + 1) {
    if (pre >= a[i]) {
      ans += a[i];
      a[i] = 0;
    } else {
      ans += pre;
      a[i] = a[i] - pre;
    }

    if (i == n) break;
    if (a[i] > b[i]) {
      ans += b[i];
      b[i] = 0;
      a[i] = a[i] - b[i];
    } else {
      ans += a[i];
      b[i] = b[i] - a[i];
      a[i] = 0;
    }
    pre = b[i];
  }
  cout << ans << endl;
  return 0;
}