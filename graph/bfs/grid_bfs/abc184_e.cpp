#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 184 E - Third Avenue
      https://atcoder.jp/contests/abc184/tasks/abc184_e
*/

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> fi(h);
  rep(i, h) cin >> fi[i];

  int sx, sy, tx, ty;
  vector<vector<P>> pl(26);
  rep(i, h) {
    rep(j, w) {
      if (fi[i][j] == 'S')
        sx = i, sy = j;
      else if (fi[i][j] == 'G')
        tx = i, ty = j;
      else if (fi[i][j] >= 'a' && fi[i][j] <= 'z')
        pl[fi[i][j] - 'a'].push_back(P(i, j));
    }
  }

  vector<bool> used(26, false);
  vector<vector<int>> dist(h, vector<int>(w, -1));
  dist[sx][sy] = 0;
  queue<P> que;
  que.push(P(sx, sy));
  while (!que.empty()) {
    auto tmp = que.front();
    que.pop();
    int x = tmp.first, y = tmp.second;
    if (fi[x][y] >= 'a' && fi[x][y] <= 'z') {
      int c = fi[x][y] - 'a';
      if (!used[c]) {
        for (auto p : pl[c]) {
          if (dist[p.first][p.second] == -1) {
            dist[p.first][p.second] = dist[x][y] + 1;
            que.push(p);
          }
        }
      }
      used[c] = true;
    }
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir], ny = y + dy[dir];
      if (nx < 0 || nx >= h || ny < 0 || ny >= w || fi[nx][ny] == '#') continue;
      if (dist[nx][ny] == -1) {
        dist[nx][ny] = dist[x][y] + 1;
        que.push(P(nx, ny));
      }
    }
  }
  cout << dist[tx][ty] << endl;
}