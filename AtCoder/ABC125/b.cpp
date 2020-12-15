#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> v(n), c(n);
  rep(i, n) cin >> v[i];
  rep(i, n) cin >> c[i];

  int ans = 0;
  for (int bit = 0; bit < (1 << n); ++bit) {
    int x = 0;
    int y = 0;
    rep(i, n) {
      if (bit & (1 << i)) {
        x += v[i];
        y += c[i];
      }
    }
    ans = max(ans, x - y);
  }

  cout << ans << endl;
  return 0;
}