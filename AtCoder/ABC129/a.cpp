#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int p, q, r;
  cin >> p >> q >> r;
  int ans = min(p + q, q + r);
  ans = min(ans, p + r);
  cout << ans << endl;
  return 0;
}