#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int x, n;
  cin >> x >> n;
  vector<int> p(n);
  rep(i, n) cin >> p[i];
  int ab = 1e6;
  int ans;
  for (int i = -300; i <= 300; i++) {
    bool t = false;
    rep(j, n) {
      if (i == p[j]) t = true;
    }
    if (t) continue;
    if (abs(x - i) < ab) {
      ab = abs(x - i);
      ans = i;
    }
  }
  cout << ans << endl;
  return 0;
}