#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b, c, k;
  cin >> a >> b >> c >> k;

  int xa = min(a, k);
  k -= xa;
  int xb = min(b, k);
  k -= xb;
  int xc = k;
  int ans = xa - xc;

  cout << ans << endl;
  return 0;
}
