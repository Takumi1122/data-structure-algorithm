#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int mod = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> s(n + 1, 0);
  rep(i, n) s[i + 1] = s[i] + a[i];

  ll ans = 0;
  rep(i, n - 1) {
    ll sum = s[n] - s[i+1];
    ans += (((a[i] % mod) * (sum % mod)) % mod);
  }

  cout << ans % mod << endl;

  return 0;
}