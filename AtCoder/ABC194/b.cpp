#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];

  int ans = 1001001001;
  rep(ai, n) rep(bi, n) {
    int now = 0;
    if (ai == bi)
      now = a[ai] + b[bi];
    else
      now = max(a[ai], b[bi]);
    ans = min(ans, now);
  }

  cout << ans << endl;
  return 0;
}