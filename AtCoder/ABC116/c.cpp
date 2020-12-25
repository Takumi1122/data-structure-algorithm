#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Data = pair<P, int>;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i, n) cin >> h[i];
  h.push_back(0);
  int ans = 0;

  while (1) {
    int now = 0;
    int mn = 1e9;
    vector<Data> p;

    rep(i, n + 1) {
      if (h[i] == 0) {
        p.push_back(make_pair(make_pair(now, i - 1), mn));
        now = i + 1;
        mn = 1e9;
        continue;
      }
      mn = min(mn, h[i]);
    }

    for (auto pi : p) {
      if (pi.second == (int)(1e9)) continue;
      for (int i = pi.first.first; i <= min(n - 1, pi.first.second); i++) {
        h[i] -= pi.second;
      }
      ans += pi.second;
    }

    bool ok = true;
    rep(i, n) if (h[i] != 0) ok = false;
    if (ok) break;
  }

  cout << ans << endl;
  return 0;
}