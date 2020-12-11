#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using LP = pair<ll, int>;

// グリッド上のBFS
// 1ターンにKマスまで動くことができる

/*
    参考リンク
    ABC 170 F - Pond Skater
      https://atcoder.jp/contests/abc170/tasks/abc170_f
*/

const int INF = 1e9;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};

int main() {
  int h, w, k;
  cin >> h >> w >> k;
  int si, sj, ti, tj;
  cin >> si >> sj >> ti >> tj;
  --si;
  --sj;
  --ti;
  --tj;
  vector<string> f(h);
  rep(i, h) cin >> f[i];

  queue<P> q;
  q.emplace(si, sj);
  vector<vector<int>> dist(h, vector<int>(w, INF));
  dist[si][sj] = 0;
  while (!q.empty()) {
    int i = q.front().first;
    int j = q.front().second;
    q.pop();
    rep(v, 4) {
      for (int ki = 1; ki <= k; ki++) {
        int ni = i + ki * di[v], nj = j + ki * dj[v];
        if (ni < 0 || ni >= h || nj < 0 || nj >= w) break;
        if (f[ni][nj] == '@') break;
        if (dist[ni][nj] <= dist[i][j]) break;
        if (dist[ni][nj] > dist[i][j] + 1) {
          dist[ni][nj] = dist[i][j] + 1;
          q.emplace(ni, nj);
        }
      }
    }
  }

  if (dist[ti][tj] == INF) dist[ti][tj] = -1;
  cout << dist[ti][tj] << endl;
  return 0;
}