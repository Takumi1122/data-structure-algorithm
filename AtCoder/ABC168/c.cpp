#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b, h, m;
  cin >> a >> b >> h >> m;
  const double PI = acos(-1);
  double As = (PI * (h * 60 + m)) / 360;
  double Bs = (PI * m) / 30;
  double cosAB = cos(abs(As - Bs));
  double ansq;
  ansq = a * a + b * b - 2 * a * b * cosAB;
  double ans;
  ans = sqrt(ansq);
  cout << fixed << setprecision(10);
  cout << ans << endl;
  return 0;
}