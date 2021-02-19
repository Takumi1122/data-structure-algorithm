#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> f(h);
  rep(i, h) cin >> f[i];

  rep(i, h) rep(j, w) {
    if (f[i][j] == '#') continue;
    int cnt = 0;
    rep(k, 8) {
      int ni = i + dx[k];
      int nj = j + dy[k];
      if (ni < 0 || h <= ni) continue;
      if (nj < 0 || w <= nj) continue;
      if (f[ni][nj] == '#') cnt++;
    }
    char c = '0' + cnt;
    f[i][j] = c;
  }

  rep(i, h) cout << f[i] << endl;
  return 0;
}