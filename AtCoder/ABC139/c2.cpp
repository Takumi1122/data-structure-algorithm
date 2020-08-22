#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i, n) cin >> h[i];
  reverse(h.begin(), h.end());
  int ans = 0;
  int val = 0;
  for (int i = 1; i < n; i++) {
    if (h[i - 1] <= h[i])
      val++;
    else
      val = 0;
    ans = max(ans, val);
  }
  cout << ans << endl;
  return 0;
}
