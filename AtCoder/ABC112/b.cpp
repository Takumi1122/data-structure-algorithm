#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, t;
  cin >> n >> t;
  vector<int> c(n), tm(n);
  rep(i, n) cin >> c[i] >> tm[i];

  int ans = 1e9;
  rep(i, n) {
    if (tm[i] > t) continue;
    ans = min(ans, c[i]);
  }

  if (ans == (int)(1e9)) {
    cout << "TLE" << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}