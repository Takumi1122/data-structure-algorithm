#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

// 最小包含円
// 三分探索

/*
    参考リンク
    ABC 151 F - Enclose All
      https://atcoder.jp/contests/abc151/tasks/abc151_f
*/

int n;
struct P {
  double x, y;
};
vector<P> p;

double dist(P a, P b) {
  double dx = a.x - b.x;
  double dy = a.y - b.y;
  return sqrt(dx * dx + dy * dy);
}

double f(double x, double y) {
  double res = 0;
  rep(i, n) { res = max(res, dist((P){x, y}, p[i])); }
  return res;
}

double g(double x) {
  double l = 0, r = 1000;
  rep(i, 80) {
    double c1 = (l * 2 + r) / 3;
    double c2 = (l + r * 2) / 3;
    if (f(x, c1) > f(x, c2))
      l = c1;
    else
      r = c2;
  }
  return f(x, l);
}

int main() {
  cin >> n;
  p = vector<P>(n);
  rep(i, n) cin >> p[i].x >> p[i].y;

  double l = 0, r = 1000;
  rep(i, 80) {
    double c1 = (l * 2 + r) / 3;
    double c2 = (l + r * 2) / 3;
    if (g(c1) > g(c2))
      l = c1;
    else
      r = c2;
  }

  double ans = g(l);
  printf("%.10f\n", ans);
  return 0;
}