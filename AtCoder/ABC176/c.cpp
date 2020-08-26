#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  int mx = 0;
  ll ans = 0;
  rep(i, n - 1) {
    mx = max(mx, a[i]);
    if (mx > a[i + 1]) {
      ans += mx - a[i + 1];
    }
  }
  cout << ans << endl;
  return 0;
}