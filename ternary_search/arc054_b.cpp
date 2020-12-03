#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

/*
    参考リンク
    ARC 054 B - ムーアの法則
      https://atcoder.jp/contests/arc054/tasks/arc054_b
*/

int main() {
  double p;
  cin >> p;

  auto f = [p](double x) { return x + p / pow(2, x / 1.5); };

  double l = 0;
  double r = 1e9;

  rep(i, 500) {
    double c1 = (l * 2 + r) / 3;
    double c2 = (l + r * 2) / 3;

    if (f(c1) > f(c2))
      l = c1;
    else
      r = c2;
  }

  printf("%.10f\n", f(l));
  return 0;
}