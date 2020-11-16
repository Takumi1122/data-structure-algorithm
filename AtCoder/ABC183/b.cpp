#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  double sx, sy, gx, gy;
  cin >> sx >> sy >> gx >> gy;
  gy = -gy;
  double ans = sx - (sy * (gx - sx) / (gy - sy));
  printf("%.15f\n", ans);
  return 0;
}