#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int t;
  cin >> t;

  rep(i, t) {
    int l, r;
    cin >> l >> r;

    if (l + l > r) {
      cout << 0 << endl;
      continue;
    }

    ll sub = r - (l + l) + 1;
    ll ans = sub * (sub + 1) / 2;
    cout << ans << endl;
  }
  return 0;
}