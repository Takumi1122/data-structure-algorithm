#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// O(n * log(m)) 累積和 + 二分探索

int main() {
  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> a(n), b(m);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];
  vector<ll> s(m + 1, 0);
  rep(i, m) s[i + 1] = s[i] + b[i];
  int ans = 0;
  ll t = 0;
  for (int i = 0; i <= n; i++) {
    if (i != 0) {
      t += a[i - 1];
    }
    if (t > k) break;
    int l = -1;
    int r = m + 1;
    while (l + 1 < r) {
      int mid = (l + r) / 2;
      if (t + s[mid] <= k) {
        l = mid;
      } else {
        r = mid;
      }
    }
    ans = max(ans, i + l);
  }
  cout << ans << endl;
  return 0;
}