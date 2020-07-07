#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end(), greater<ll>());
  ll ans = 0;
  int n1 = n - 1;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      ans += a[i];
      n1--;
      if (n1 == 0) break;
    } else {
      ans += a[i];
      n1--;
      if (n1 == 0) break;
      ans += a[i];
      n1--;
      if (n1 == 0) break;
    }
  }
  cout << ans << endl;
  return 0;
}