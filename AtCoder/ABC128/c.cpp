#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> s(m, vector<int>(n, 0));
  vector<int> p(m);
  rep(i, m) {
    int k;
    cin >> k;
    rep(j, k) {
      int sj;
      cin >> sj;
      s[i][sj - 1] = 1;
    }
  }
  rep(i, m) cin >> p[i];

  int ans = 0;
  for (int bit = 0; bit < (1 << n); ++bit) {
    vector<int> cnt(m);
    rep(i, n) {
      if (bit & (1 << i)) {
        rep(j, m) {
          if (s[j][i]) cnt[j]++;
        }
      }
    }
    bool ok = true;
    rep(i, m) {
      if (cnt[i] % 2 != p[i]) ok = false;
    }
    if (ok) ans++;
  }
  cout << ans << endl;
  return 0;
}