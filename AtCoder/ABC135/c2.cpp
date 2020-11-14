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

  rep(i, n) {
    if (b[i] >= a[i]) {
      ans += a[i];
      b[i] = b[i] - a[i];
      a[i] = 0;
    } else {
      ans += b[i];
      a[i] = a[i] - b[i];
      b[i] = 0;
    }

    if (b[i] >= a[i + 1]) {
      ans += a[i + 1];
      b[i] = b[i] - a[i + 1];
      a[i + 1] = 0;
    } else {
      ans += b[i];
      a[i + 1] = a[i + 1] - b[i];
      b[i] = 0;
    }
  }

  cout << ans << endl;
  return 0;
}