#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

/*
    参考リンク
    ABC 74 C - Sugar Water
      https://atcoder.jp/contests/abc074/tasks/arc083_a
*/

int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;

  // con: 濃度
  double con = 0.0;
  int water = 0;
  int sugar = 0;

  for (int w = 0; w <= 30; w++) {
    for (int x = 0; x <= 30; x++) {
      for (int y = 0; y <= (f + c - 1) / c; y++) {
        for (int z = 0; z <= (f + d - 1) / d; z++) {
          int ww = a * w + b * x;
          int sw = c * y + d * z;
          int sum = 100 * ww + sw;

          // 砂糖が全て溶けているか
          if (sum <= f && sw <= ww * e) {
            if (con < (double)sw / sum) {
              con = (double)sw / sum;
              water = 100 * ww;
              sugar = sw;
            }
          }
        }
      }
    }
  }
  if (con == 0) water = 100 * a;

  cout << water + sugar << " " << sugar << endl;
  return 0;
}