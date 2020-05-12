#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1e9;

int main() {
  int n, m, x;
  cin >> n >> m >> x;
  vector<int> c(n);
  vector<vector<int>> a(n, vector<int>(m));
  rep(i, n) {
    cin >> c[i];
    rep(j, m) cin >> a[i][j];
  }
  int ans = INF;
  for (int bit = 0; bit < (1 << n); ++bit) {
    int sum[m] = {0};
    int cost = 0;
    for (int i = 0; i < n; ++i) {
      if (bit & (1 << i)) {
        rep(j, m) sum[j] += a[i][j];
        cost += c[i];
      }
    }

    bool ok = true;

    rep(j, m) {
      if (sum[j] < x) ok = false;
    }
    if (ok) ans = min(ans, cost);
  }

  if (ans != INF) {
    cout << ans << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}