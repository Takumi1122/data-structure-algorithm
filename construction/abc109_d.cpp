#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
using PP = pair<P, P>;

// パリティ ジグザク

/*
    参考リンク
    ABC 109 D - Make Them Even
      https://atcoder.jp/contests/abc109/tasks/abc109_d
*/

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w, 0));
  rep(i, h) rep(j, w) cin >> a[i][j];

  vector<PP> ans;
  int x = 0, y = 0;
  rep(i, h * w - 1) {
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

    if (a[x][y] % 2 == 1) {
      ans.push_back(PP(P(x, y), P(nx, ny)));
      a[nx][ny]++;
      a[x][y]--;
    }
    x = nx, y = ny;
  }

  cout << ans.size() << endl;
  for (auto p : ans) {
    cout << p.first.first + 1 << " " << p.first.second + 1 << " "
         << p.second.first + 1 << " " << p.second.second + 1 << endl;
  }
}