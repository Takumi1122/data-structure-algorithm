#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];
  ll ans = 0;
  rep(i, n) for (int j = i + 1; j < n; j++) {
    int dx = x[i] - x[j];
    int dy = y[i] - y[j];
    if (dx >= 0) {
      if (dy <= dx && -dx <= dy) ans++;
    } else {
      if (dy >= dx && -dx >= dy) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}