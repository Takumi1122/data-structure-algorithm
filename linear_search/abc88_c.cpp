#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 全探索

/*
    参考リンク
    ABC 88 C - Takahashi's Information
      https://atcoder.jp/contests/abc088/tasks/abc088_c
*/

int c[3][3];

int main() {
  rep(i, 3) rep(j, 3) cin >> c[i][j];

  bool ok = false;
  for (int a1 = -100; a1 <= 100; a1++) {
    for (int a2 = -100; a2 <= 100; a2++) {
      for (int a3 = -100; a3 <= 100; a3++) {
        if (c[0][0] - a1 != c[1][0] - a2) continue;
        if (c[1][0] - a2 != c[2][0] - a3) continue;
        if (c[0][1] - a1 != c[1][1] - a2) continue;
        if (c[1][1] - a2 != c[2][1] - a3) continue;
        if (c[0][2] - a1 != c[1][2] - a2) continue;
        if (c[1][2] - a2 != c[2][2] - a3) continue;
        ok = true;
      }
    }
  }

  if (ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}