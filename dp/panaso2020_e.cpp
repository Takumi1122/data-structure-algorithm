#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MX = 2005;
bool d[3][3][MX];

int main() {
  vector<string> s(3);
  rep(i, 3) cin >> s[i];
  sort(s.begin(), s.end());
  int ans = MX * 3;
  do {
    rep(i, 3) rep(j, 3) rep(k, s[i].size()) {
      if (i >= j) continue;
      bool ok = true;
      for (int ni = k; ni < s[i].size(); ni++) {
        int nj = ni - k;
        if (nj >= s[j].size()) break;
        if (s[i][ni] == '?' || s[j][nj] == '?') continue;
        if (s[i][ni] != s[j][nj]) ok = false;
      }
      d[i][j][k] = ok;
    }

    auto f = [&](int i, int j, int k) {
      if (k >= s[i].size()) return true;
      return d[i][j][k];
    };

    rep(x, MX) rep(y, MX) {
      if (!f(0, 1, x)) continue;
      if (!f(1, 2, y)) continue;
      if (!f(0, 2, x + y)) continue;
      int now = 0;
      now = max<int>(now, s[0].size());
      now = max<int>(now, x + s[1].size());
      now = max<int>(now, x + y + s[2].size());
      ans = min(ans, now);
    }
  } while (next_permutation(s.begin(), s.end()));
  cout << ans << endl;
  return 0;
}