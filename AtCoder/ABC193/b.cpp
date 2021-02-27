#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), p(n), x(n);
  rep(i, n) cin >> a[i] >> p[i] >> x[i];
  int ans = 1001001001;
  rep(i, n) {
    if (a[i] >= x[i]) continue;
    ans = min(ans, p[i]);
  }

  if (ans == 1001001001) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}