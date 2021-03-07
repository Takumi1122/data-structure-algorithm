#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> sum(n + 1);
  rep(i, n) sum[i + 1] = sum[i] + a[i];

  ll ans = 0;
  rep(i, n) ans += ((n - 1) * a[i] * a[i]);
  rep(i, n - 1) {
    ll x = -2 * a[i] * (sum[n] - sum[i + 1]);
    ans += x;
  }

  cout << ans << endl;
  return 0;
}