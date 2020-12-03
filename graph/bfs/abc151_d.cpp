#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 151 D - Maze Master
      https://atcoder.jp/contests/abc151/tasks/abc151_d
*/

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> f(h);
  rep(i, h) cin >> f[i];

  vector<P> s;
  rep(i, h) rep(j, w) {
    if (f[i][j] == '.') {
      s.push_back(P(i, j));
    }
  }

  int ans = 0;

  rep(i, s.size()) {
    vector<vector<int>> dist(h, vector<int>(w, -1));
    dist[s[i].first][s[i].second] = 0;

    queue<pair<int, int>> que;
    que.push(P(s[i].first, s[i].second));

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

    rep(j, h) rep(k, w) ans = max(ans, dist[j][k]);
  }

  cout << ans << endl;
  return 0;
}