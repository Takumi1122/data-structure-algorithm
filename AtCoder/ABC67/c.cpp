#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> s(n + 1);
  rep(i, n) s[i + 1] = s[i] + a[i];

  ll ans = 1e18;
  for (int i = 1; i < n; i++) {
    ll x = s[i];
    ll y = s[n] - s[i];
    ans = min(ans, abs(x - y));
  }

  cout << ans << endl;
  return 0;
}