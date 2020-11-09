#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 上下左右DFS

/*
    参考リンク
    ABC 182 E - Akari
      https://atcoder.jp/contests/abc182/tasks/abc182_e
*/

const int di[4] = {0, 1, 0, -1};
const int dj[4] = {1, 0, -1, 0};

int main() {
  int h, w, n, m;
  cin >> h >> w >> n >> m;
  vector<vector<int>> grid(h, vector<int>(w, 0));
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    grid[a][b] = 1;
  }
  rep(i, m) {
    int c, d;
    cin >> c >> d;
    c--;
    d--;
    grid[c][d] = -1;
  }

  rep(i, h) rep(j, w) {
    if (grid[i][j] == 1) {
      rep(k, 4) {
        int ni = i, nj = j;
        while (true) {
          ni += di[k], nj += dj[k];
          if (ni < 0 || nj < 0 || ni >= h || nj >= w) break;
          if (grid[ni][nj] == -1 || grid[ni][nj] == 1) break;
          grid[ni][nj] = 2;
        }
      }
    }
  }

  int ans = 0;
  rep(i, h) rep(j, w) if (grid[i][j] > 0) ans++;
  cout << ans << endl;
}