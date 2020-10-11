#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> f(h);
  rep(i, h) cin >> f[i];

  ll ans = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w - 1; j++) {
      if (f[i][j] == '.' && f[i][j + 1] == '.') ans++;
    }
  }

  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h - 1; j++) {
      if (f[j][i] == '.' && f[j + 1][i] == '.') ans++;
    }
  }

  cout << ans << endl;
  return 0;
}