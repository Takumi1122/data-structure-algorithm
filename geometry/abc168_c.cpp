#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// torad: (PI * deg) / 180
// todeg: (rad * 180) / PI

/*
    参考リンク
    ABC 168 C - : (Colon)
      https://atcoder.jp/contests/abc168/tasks/abc168_c
*/

int main() {
  int a, b, h, m;
  cin >> a >> b >> h >> m;

  const double PI = acos(-1);
  double As = (PI * (h * 60 + m)) / 360;
  double Bs = (PI * m) / 30;
  double cosAB = cos(abs(As - Bs));

  double ansq = a * a + b * b - 2 * a * b * cosAB;
  double ans = sqrt(ansq);

  printf("%.15f\n", ans);
  return 0;
}