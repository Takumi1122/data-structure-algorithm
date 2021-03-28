#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int h, w, x, y;
  cin >> h >> w >> x >> y;
  x--;
  y--;
  vector<string> f(h);
  rep(i, h) cin >> f[i];

  int ans = 0;
  for (int i = y; i < w; i++) {
    if (f[x][i] == '.') {
      ans++;
    } else {
      break;
    }
  }
  for (int i = y; i >= 0; i--) {
    if (f[x][i] == '.') {
      ans++;
    } else {
      break;
    }
  }
  for (int i = x; i < h; i++) {
    if (f[i][y] == '.') {
      ans++;
    } else {
      break;
    }
  }
  for (int i = x; i >= 0; i--) {
    if (f[i][y] == '.') {
      ans++;
    } else {
      break;
    }
  }

  if (f[x][y] == '#') {
    cout << 0 << endl;
  } else {
    cout << ans - 3 << endl;
  }
  return 0;
}