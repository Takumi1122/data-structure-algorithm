#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  rep(i, n) cin >> x[i];
  int ans = 1001001001;
  for (int p = 1; p <= 100; ++p) {
    int now = 0;
    rep(i, n) now += (x[i] - p) * (x[i] - p);
    ans = min(ans, now);
  }
  cout << ans << endl;
  return 0;
}
