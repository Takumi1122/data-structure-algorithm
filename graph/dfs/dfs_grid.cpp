#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// sからtへ辿り着けるか(グリッドグラフの場合)

// 四方向への移動ベクトル
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// 入力
int H, W;
vector<string> field;

// 探索
bool seen[510][510];  // seen[h][w] := マス (h, w) が検知済みかどうか
void dfs(int h, int w) {
  seen[h][w] = true;

  // 四方向を探索
  for (int dir = 0; dir < 4; ++dir) {
    int nh = h + dx[dir];
    int nw = w + dy[dir];

    // 場外アウトしたり、移動先が壁の場合はスルー
    if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
    if (field[nh][nw] == '#') continue;

    // 移動先が探索済みの場合
    if (seen[nh][nw]) continue;

    // 再帰的に探索
    dfs(nh, nw);
  }
}

int main() {
  // 入力受け取り
  cin >> H >> W;
  field.resize(H);
  rep(h, H) cin >> field[h];

  // s と g のマスを特定する
  int sh, sw, gh, gw;
  rep(h, H) {
    rep(w, W) {
      if (field[h][w] == 's') sh = h, sw = w;
      if (field[h][w] == 'g') gh = h, gw = w;
    }
  }

  // 探索開始
  memset(seen, 0, sizeof(seen));  // seen 配列全体を false に初期化
  dfs(sh, sw);

  // 結果
  if (seen[gh][gw])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}