#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> b(n - 1);
  rep(i, n - 1) cin >> b[i];

  if (n == 2) {
    cout << b[0] * 2 << endl;
    return 0;
  }

  vector<int> a(n);
  rep(i, n) {
    if (i == 0) {
      a[i] = b[i];
      continue;
    }

    if (i == n - 1) {
      a[i] = b[i - 1];
      break;
    }

    a[i] = min(b[i], b[i - 1]);
  }

  ll ans = 0;
  rep(i, n) ans += a[i];

  cout << ans << endl;
  return 0;
}