#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// maxについての扱い

/*
    参考リンク
    ABC 112 C - Pyramid
      https://atcoder.jp/contests/abc112/tasks/abc112_c
*/

int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n), h(n);
  rep(i, n) cin >> x[i] >> y[i] >> h[i];

  for (int cx = 0; cx <= 100; cx++) {
    for (int cy = 0; cy <= 100; cy++) {
      int H = -1;
      int Hmax = 2e9;
      bool ok = true;

      rep(i, n) {
        int d = abs(cx - x[i]) + abs(cy - y[i]);
        if (h[i] > 0) {
          int H2 = h[i] + d;
          if (H > 0 && H != H2) {
            ok = false;
            break;
          } else {
            H = H2;
          }
        } else {
          Hmax = min(Hmax, d);
        }
      }

      if (ok && H <= Hmax) {
        cout << cx << " " << cy << " " << H << endl;
        return 0;
      }
    }
  }
}