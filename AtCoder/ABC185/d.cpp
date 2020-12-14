#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  rep(i, m) cin >> a[i];

  if (m == 0) {
    cout << 1 << endl;
    return 0;
  }
  if (m == n) {
    cout << 0 << endl;
    return 0;
  }

  sort(a.begin(), a.end());

  int mn = 1e9;
  if (a[0] - 1 > 0) mn = a[0] - 1;
  rep(i, m - 1) {
    int sub = a[i + 1] - a[i] - 1;
    if (sub > 0) mn = min(mn, sub);
  }
  if (n - a[m - 1] > 0) mn = min(mn, n - a[m - 1]);

  ll ans = 0;
  if (a[0] - 1 > 0) ans = (a[0] - 1 + mn - 1) / mn;
  rep(i, m - 1) {
    int sub = a[i + 1] - a[i] - 1;
    if (sub > 0) {
      int cnt = (sub + mn - 1) / mn;
      ans += cnt;
    }
  }
  if (n - a[m - 1] > 0) {
    int cnt = (n - a[m - 1] + mn - 1) / mn;
    ans += cnt;
  }

  cout << ans << endl;
  return 0;
}