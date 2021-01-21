#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> f(h);
  rep(i, h) cin >> f[i];

  bool ok = true;
  rep(i, h) rep(j, w) {
    if (f[i][j] == '#') {
      if (i - 1 >= 0 && f[i - 1][j] == '#') continue;
      if (i + 1 < h && f[i + 1][j] == '#') continue;
      if (j - 1 >= 0 && f[i][j - 1] == '#') continue;
      if (j + 1 < w && f[i][j + 1] == '#') continue;
      ok = false;
    }
  }

  if (ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}