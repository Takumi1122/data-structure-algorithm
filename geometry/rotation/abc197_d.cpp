#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

/*
    回転行列 反時計回り
    x' = xcosθ - ysinθ
    y' = xsinθ + ycosθ
*/

/*
    参考リンク
    ABC 197 D - Opposite
      https://atcoder.jp/contests/abc197/tasks/abc197_d
*/

const double PI = acos(-1.0);

int main() {
  int n;
  cin >> n;
  double x, y, xk, yk;
  cin >> x >> y >> xk >> yk;

  // 中点
  double ox = (x + xk) / 2;
  double oy = (y + yk) / 2;
  // 回転の角度(rad)
  double rad = 2 * PI / n;
  double x_ox = x - ox;
  double y_oy = y - oy;
  // 回転
  double ansx = ox + (x_ox * cos(rad) - y_oy * sin(rad));
  double ansy = oy + (x_ox * sin(rad) + y_oy * cos(rad));

  printf("%.15f %.15f\n", ansx, ansy);
  return 0;
}