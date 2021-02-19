#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// n点のうちk個以上含む長方形の最小面積 O(n^5)
// n = 50 くらい

/*
    参考リンク
    ABC 75 D - Axis-Parallel Rectangle
      https://atcoder.jp/contests/abc075/tasks/abc075_d
*/

int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> x(n), y(n);
  vector<ll> xary, yary;
  rep(i, n) {
    cin >> x[i] >> y[i];
    xary.push_back(x[i]);
    yary.push_back(y[i]);
  }
  sort(xary.begin(), xary.end());
  sort(yary.begin(), yary.end());

  ll ans = (xary[n - 1] - xary[0]) * (yary[n - 1] - yary[0]);
  rep(xi, n) {
    for (int xj = xi + 1; xj < n; ++xj) {
      rep(yi, n) {
        for (int yj = yi + 1; yj < n; ++yj) {
          int num = 0;
          ll lx = xary[xi], rx = xary[xj];
          ll by = yary[yi], uy = yary[yj];
          rep(i, n) {
            if (lx <= x[i] && x[i] <= rx && by <= y[i] && y[i] <= uy) {
              num++;
            }
          }
          if (num >= k) ans = min(ans, (rx - lx) * (uy - by));
        }
      }
    }
  }

  cout << ans << endl;
  return 0;
}