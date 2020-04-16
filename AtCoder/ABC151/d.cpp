#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/* 4 方向への隣接頂点への移動を表すベクトル */
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  /* 縦と横の長さ */
  int h, w;
  cin >> h >> w;

  /* 盤面 */
  vector<string> f(h);
  rep(i, h) { cin >> f[i]; }

  /* スタート地点とゴール地点 */
  vector<P> s;
  rep(i, h) {
    rep(j, w) {
      if (f[i][j] == '.') {
        s.push_back(make_pair(i, j));
      }
    }
  }

  int mx = 0;

  rep(i, s.size()) {
    // 各セルの最短距離 (訪れていないところは -1 としておく)
    vector<vector<int>> dist(h, vector<int>(w, -1));
    dist[s[i].first][s[i].second] = 0;  // スタートを 0 に

    // 「一度見た頂点」のうち「まだ訪れていない頂点」を表すキュー
    queue<pair<int, int>> que;
    que.push(make_pair(s[i].first, s[i].second));  // スタートを push

    ////////////////////////////////////////
    /* 幅優先探索を実施 */
    ////////////////////////////////////////

    /* キューが空になるまで */
    while (!que.empty()) {
      pair<int, int> current_pos = que.front();  // キューの先頭を見る (C++
                                                 // ではこれをしても pop しない)
      int x = current_pos.first;
      int y = current_pos.second;
      que.pop();  // キューから pop を忘れずに

      // 隣接頂点を探索
      for (int direction = 0; direction < 4; ++direction) {
        int next_x = x + dx[direction];
        int next_y = y + dy[direction];
        if (next_x < 0 || next_x >= h || next_y < 0 || next_y >= w)
          continue;                              // 場外アウトならダメ
        if (f[next_x][next_y] == '#') continue;  // 壁はダメ

        // まだ見ていない頂点なら push
        if (dist[next_x][next_y] == -1) {
          que.push(make_pair(next_x, next_y));
          dist[next_x][next_y] =
              dist[x][y] + 1;  // (next_x, next_y) の距離も更新
        }
      }
    }

    rep(k, h) {
      rep(t, w) { mx = max(mx, dist[k][t]); }
    }
  }
  cout << mx << endl;
}