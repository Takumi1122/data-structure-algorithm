#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 二次元累積和

int main() {
  // 入力: h × w のグリッド
  int h, w;
  cin >> h >> w;
  vector<vector<int> > a(h, vector<int>(w));
  rep(i, h) rep(j, w) cin >> a[i][j];

  // 二次元累積和
  vector<vector<int> > s(h + 1, vector<int>(w + 1, 0));
  rep(i, h) rep(j, w) s[i + 1][j + 1] =
      s[i][j + 1] + s[i + 1][j] - s[i][j] + a[i][j];

  // クエリ [x1, x2) × [y1, y2) の長方形区域の和
  int q;
  cin >> q;
  rep(i, q) {
    int x1, x2, y1, y2;
    cin >> x1 >> x2 >> y1 >> y2;
    cout << s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1] << endl;
  }
}