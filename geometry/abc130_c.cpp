#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 直線が長方形の対角線の交点を通る = 直線が長方形を二等分する

/*
    参考リンク
    ABC 130 C - Rectangle Cutting
      https://atcoder.jp/contests/abc130/tasks/abc130_c
*/

int main() {
  double w, h, x, y;
  cin >> w >> h >> x >> y;
  double ans = w * h / 2;
  cout << fixed << setprecision(10) << ans << " ";

  if (x * 2 == w && y * 2 == h)
    cout << 1 << endl;
  else
    cout << 0 << endl;
}