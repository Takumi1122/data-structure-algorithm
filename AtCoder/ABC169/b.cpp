#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) {
    cin >> a[i];
    if (a[i] == 0) {
      cout << 0 << endl;
      return 0;
    }
  }
  ll ans = 1;
  const ll INF = 1e18;
  rep(i, n) {
    if (a[i] > INF) {
      cout << -1 << endl;
      return 0;
    }
    if (INF / ans < a[i]) {
      cout << -1 << endl;
      return 0;
    }
    ans *= a[i];
  }
  if (ans > INF) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}