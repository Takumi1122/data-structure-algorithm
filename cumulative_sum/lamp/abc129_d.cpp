#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 129 D - Lamp
      https://atcoder.jp/contests/abc129/tasks/abc129_d
*/

// 各マスから左側/右側/上側/下側に何マス行ったら壁にぶつかるか
int Left[2100][2100], Right[2100][2100], Up[2100][2100], Down[2100][2100];

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> fi(h);
  rep(i, h) cin >> fi[i];

  // 前処理
  rep(i, h) {
    int cur = 0;
    rep(j, w) {
      if (fi[i][j] == '#')
        cur = 0;
      else
        ++cur;
      Left[i][j] = cur;
    }
  }

  rep(i, h) {
    int cur = 0;
    for (int j = w - 1; j >= 0; --j) {
      if (fi[i][j] == '#')
        cur = 0;
      else
        ++cur;
      Right[i][j] = cur;
    }
  }

  rep(j, w) {
    int cur = 0;
    rep(i, h) {
      if (fi[i][j] == '#')
        cur = 0;
      else
        ++cur;
      Up[i][j] = cur;
    }
  }

  rep(j, w) {
    int cur = 0;
    for (int i = h - 1; i >= 0; --i) {
      if (fi[i][j] == '#')
        cur = 0;
      else
        ++cur;
      Down[i][j] = cur;
    }
  }

  // 集計
  int res = 0;
  rep(i, h) {
    rep(j, w) {
      if (fi[i][j] == '#') continue;
      res = max(res, Left[i][j] + Right[i][j] + Up[i][j] + Down[i][j] - 3);
    }
  }
  cout << res << endl;
}