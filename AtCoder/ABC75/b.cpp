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

  rep(i, h) rep(j, w) {
    if (f[i][j] == '#') continue;
    int cnt = 0;
    if (i + 1 < h && f[i + 1][j] == '#') cnt++;
    if (j + 1 < w && f[i][j + 1] == '#') cnt++;
    if (i - 1 >= 0 && f[i - 1][j] == '#') cnt++;
    if (j - 1 >= 0 && f[i][j - 1] == '#') cnt++;
    if (i + 1 < h && j + 1 < w && f[i + 1][j + 1] == '#') cnt++;
    if (i - 1 >= 0 && j - 1 >= 0 && f[i - 1][j - 1] == '#') cnt++;
    if (i + 1 < h && j - 1 >= 0 && f[i + 1][j - 1] == '#') cnt++;
    if (i - 1 >= 0 && j + 1 < w && f[i - 1][j + 1] == '#') cnt++;
    char c = '0' + cnt;
    f[i][j] = c;
  }

  rep(i, h) cout << f[i] << endl;
  return 0;
}