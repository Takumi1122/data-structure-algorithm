#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i, n) cin >> h[i];

  /* しゃくとり法 */
  int ans = 0;
  int right = 1;  // [0, 1) は確実に条件を満たす
  for (int left = 0; left < n; ++left) {
    // right を 1 個進めたものが条件を満たすかどうか
    while (right < n && (right <= left || h[right - 1] >= h[right])) {
      ++right;
    }
    ans = max(ans, right - left - 1);
    if (left == right) ++right;
  }

  cout << ans << endl;
  return 0;
}