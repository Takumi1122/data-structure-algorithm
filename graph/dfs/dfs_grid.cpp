#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// sからtへ辿り着けるか(グリッドグラフの場合)

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int H, W;
vector<string> f;

// 探索
bool seen[510][510];
void dfs(int h, int w) {
  seen[h][w] = true;

  rep(d, 4) {
    int nh = h + dx[d];
    int nw = w + dy[d];

    if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
    if (f[nh][nw] == '#') continue;

    if (seen[nh][nw]) continue;
    dfs(nh, nw);
  }
}

int main() {
  cin >> H >> W;
  f.resize(H);
  rep(i, H) cin >> f[i];

  int sh, sw, gh, gw;
  rep(i, H) {
    rep(j, W) {
      if (f[i][j] == 's') sh = i, sw = j;
      if (f[i][j] == 'g') gh = i, gw = j;
    }
  }

  memset(seen, 0, sizeof(seen));
  dfs(sh, sw);

  if (seen[gh][gw])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}