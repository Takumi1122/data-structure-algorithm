#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 直線の直交・平行判定

/*
    参考リンク
    AIZU ONLINE JUDGE
      https://onlinejudge.u-aizu.ac.jp/problems/CGL_2_A
*/

int main() {
  int q;
  cin >> q;
  rep(i, q) {
    int x0, y0;
    int x1, y1;
    int x2, y2;
    int x3, y3;
    cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int dx01 = x0 - x1;
    int dy01 = y0 - y1;
    int dx23 = x2 - x3;
    int dy23 = y2 - y3;
    // 傾きが同じかどうか
    if (dx01 * dy23 == dx23 * dy01) {
      cout << 2 << endl;
      continue;
    }
    // 内積が0かどうか
    if (dx01 * dx23 + dy01 * dy23 == 0) {
      cout << 1 << endl;
      continue;
    }
    cout << 0 << endl;
  }
}