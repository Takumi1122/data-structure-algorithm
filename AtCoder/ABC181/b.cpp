#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> b(n);
  rep(i, n) cin >> a[i] >> b[i];
  ll ans = 0;
  rep(i, n) {
    ll suma = a[i] * (a[i] - 1) / 2;
    ll sumb = b[i] * (b[i] + 1) / 2;
    ans += sumb - suma;
  }
  cout << ans << endl;
  return 0;
}