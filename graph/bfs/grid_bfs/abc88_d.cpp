#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

/*
    参考リンク
    ABC 88 D - Grid Repainting
      https://atcoder.jp/contests/abc088/tasks/abc088_d
*/

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> f(h);
  rep(i, h) cin >> f[i];

  int cnt = 0;
  rep(i, h) rep(j, w) {
    if (f[i][j] == '.') cnt++;
  }

  vector<vector<int>> dist(h, vector<int>(w, -1));
  dist[0][0] = 0;
  queue<P> que;
  que.push(P(0, 0));

  while (!que.empty()) {
    auto now = que.front();
    int x = now.first;
    int y = now.second;
    que.pop();

    rep(d, 4) {
      int nx = x + dx[d];
      int ny = y + dy[d];
      if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
      if (f[nx][ny] == '#') continue;

      if (dist[nx][ny] == -1) {
        que.push(P(nx, ny));
        dist[nx][ny] = dist[x][y] + 1;
      }
    }
  }

  if (dist[h - 1][w - 1] == -1) {
    cout << -1 << endl;
  } else {
    cout << cnt - dist[h - 1][w - 1] - 1 << endl;
  }
  return 0;
}