#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// x軸方向とy軸方向についての向き変更
// x座標とy座標を分けて考える

/*
    参考リンク
    ABC 82 D - FT Robot
      https://atcoder.jp/contests/abc082/tasks/arc087_b
*/

const ll MAX_N = 8020;
// dpx[i][j]: x軸方向に動いた回数i，i回目にロボットが到達できるx座標j
bool dpx[MAX_N][MAX_N * 2], dpy[MAX_N][MAX_N * 2];

int main() {
  string s;
  cin >> s;
  int x, y;
  cin >> x >> y;

  vector<int> t;
  int cnt = 0;
  rep(i, s.size()) {
    if (s[i] == 'T') {
      if (cnt != 0) t.push_back(cnt);
      t.push_back(0);
      cnt = 0;
    } else {
      cnt++;
      if (i == s.size() - 1) t.push_back(cnt);
    }
  }

  // 原点を (8000,8000) としている
  dpx[0][8000] = true;
  dpy[0][8000] = true;

  bool flag = false;
  // trueならx軸について見ている
  bool xy = true;
  int cnt_x = 0;
  int cnt_y = 0;

  rep(i, t.size()) {
    if (t[i] == 0) {
      xy = !xy;
    } else if (xy) {
      cnt_x++;
      rep(j, MAX_N * 2) {
        if (dpx[cnt_x - 1][j]) {
          if (j + t[i] < MAX_N * 2) dpx[cnt_x][j + t[i]] = true;
          if (j - t[i] >= 0 && flag) dpx[cnt_x][j - t[i]] = true;
        }
      }
    } else if (!xy) {
      cnt_y++;
      rep(j, MAX_N * 2) {
        if (dpy[cnt_y - 1][j]) {
          if (j + t[i] < MAX_N * 2) dpy[cnt_y][j + t[i]] = true;
          if (j - t[i] >= 0) dpy[cnt_y][j - t[i]] = true;
        }
      }
    }
    if (!flag) flag = true;
  }

  cout << ((dpx[cnt_x][x + 8000] && dpy[cnt_y][y + 8000]) ? "Yes" : "No")
       << endl;
  return 0;
}