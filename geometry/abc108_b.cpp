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
    ABC 108 B - Ruined Square
      https://atcoder.jp/contests/abc108/tasks/abc108_b
*/

int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  int dx = x2 - x1;
  int dy = y2 - y1;
  int x = x2;
  int y = y2;

  rep(i, 2) {
    int _dx = -dy;
    int _dy = dx;
    dx = _dx;
    dy = _dy;

    x = x + dx;
    y = y + dy;

    printf("%d %d", x, y);
    if (i == 0)
      printf(" ");
    else
      printf("\n");
  }
  return 0;
}