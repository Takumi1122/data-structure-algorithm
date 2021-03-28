#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// あるマスから上下左右に見ていく

int di[] = {-1, 0, 1, 0};
int dj[] = {0, -1, 0, 1};

int main() {
  int h, w, x, y;
  cin >> h >> w >> x >> y;
  --x;
  --y;
  vector<string> s(h);
  rep(i, h) cin >> s[i];

  int ans = 1;
  rep(v, 4) {
    int ni = x, nj = y;
    while (1) {
      ni += di[v];
      nj += dj[v];
      if (ni < 0 || nj < 0 || ni >= h || nj >= w) break;
      if (s[ni][nj] == '#') break;
      ++ans;
    }
  }

  cout << ans << endl;
  return 0;
}