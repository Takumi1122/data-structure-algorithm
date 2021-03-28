#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 二次元幾何は複素数で考えると楽になるかもしれない
// 複素数は回転を簡単に扱える

/*
    参考リンク
    ABC 197 D - Opposite
      https://atcoder.jp/contests/abc197/tasks/abc197_d
*/

using C = complex<double>;
C inC() {
  double x, y;
  cin >> x >> y;
  return C(x, y);
}

int main() {
  int n;
  cin >> n;
  C s = inC();
  C t = inC();

  C o = (s + t) / 2.0;
  double PI = acos(-1);
  double rad = 2 * PI / n;
  // 反時計回りにrad回転させる
  C r(cos(rad), sin(rad));
  C ans = o + (s - o) * r;

  printf("%.10f %.10f\n", ans.real(), ans.imag());
  return 0;
}