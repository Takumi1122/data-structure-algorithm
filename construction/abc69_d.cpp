#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

/*
    参考リンク
    ABC 69 D - Grid Coloring
      https://atcoder.jp/contests/abc069/tasks/arc080_b
*/

int main() {
  int h, w, n;
  cin >> h >> w >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<vector<int>> ans(h, vector<int>(w));
  int x = 0;
  int y = 0;
  int ni = 0;
  int c = a[0];

  rep(i, h * w) {
    int nx = x, ny = y;
    if (x % 2 == 0) {
      if (ny == w - 1)
        ++nx;
      else
        ++ny;
    } else {
      if (ny == 0)
        ++nx;
      else
        --ny;
    }

    if (c >= 1) {
      ans[x][y] = ni + 1;
      c--;
    } else {
      ni++;
      c = a[ni];
      ans[x][y] = ni + 1;
      c--;
    }
    x = nx, y = ny;
  }

  rep(i, h) {
    rep(j, w) {
      if (j != w - 1) {
        cout << ans[i][j] << " ";
      } else {
        cout << ans[i][j] << endl;
      }
    }
  }
  return 0;
}