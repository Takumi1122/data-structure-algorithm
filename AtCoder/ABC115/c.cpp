#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> h(n);
  rep(i, n) cin >> h[i];

  sort(h.begin(), h.end());
  ll ans = 1e18;
  rep(i, n - k + 1) {
    ll sum = abs(h[i + k - 1] - h[i]);
    ans = min(ans, sum);
  }

  cout << ans << endl;
  return 0;
}