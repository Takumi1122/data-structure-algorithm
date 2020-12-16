#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  vector<int> a(5);
  rep(i, 5) cin >> a[i];

  int ans = 1e9;
  do {
    int now = 0;
    rep(i, 5) {
      now += a[i];
      if (now % 10 == 0) continue;
      if (i == 4) continue;
      now += (10 - now % 10);
    }
    ans = min(ans, now);
  } while (next_permutation(a.begin(), a.end()));

  cout << ans << endl;
  return 0;
}