#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    // 座標圧縮 2次元
    (X1,Y1),(X2,Y2)という二点で表されるもの（長方形や直線など）について、
    行か列の片方（X1とX2 or Y1とY2）を座標圧縮する（副作用）
    返り値: ソートされ重複要素を除いた値
    計算量: O(n * log(n))
*/

// 蟻本P150 : 領域の個数

template <class T>
vector<T> compress(vector<T> &C1, vector<T> &C2, int w) {
  vector<T> vals;
  int n = (int)C1.size();
  rep(i, n) {
    // その位置と、一つ隣を確保(隣を確保しないと空白が埋まってしまうことがある)
    for (T d = -1; d <= 1; d++) {
      T tc1 = C1[i] + d;
      T tc2 = C2[i] + d;
      if (1 <= tc1 && tc1 <= w) vals.push_back(tc1);
      if (1 <= tc2 && tc2 <= w) vals.push_back(tc2);
    }
  }

  // ソート
  sort(vals.begin(), vals.end());

  // 隣り合う重複を削除(unique), 末端のゴミを削除(erase)
  vals.erase(unique(vals.begin(), vals.end()), vals.end());

  rep(i, n) {
    C1[i] = lower_bound(vals.begin(), vals.end(), C1[i]) - vals.begin();
    C2[i] = lower_bound(vals.begin(), vals.end(), C2[i]) - vals.begin();
  }

  return vals;
}

// 四方向への移動ベクトル
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int w, h, n;
  cin >> w >> h >> n;
  vector<int> x1(n), y1(n), x2(n), y2(n);
  rep(i, n) cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];

  // 座標圧縮
  vector<int> X = compress(x1, x2, w);
  vector<int> Y = compress(y1, y2, h);

  // 塗りつぶし
  int W = (int)X.size();
  int H = (int)Y.size();
  vector<vector<bool>> F(W, vector<bool>(H, false));
  rep(i, n) {
    for (int x = x1[i]; x <= x2[i]; x++) {
      for (int y = y1[i]; y <= y2[i]; y++) {
        F[x][y] = true;
      }
    }
  }

  // 領域を数える
  ll ans = 0;
  for (int x = 0; x < W; x++) {
    for (int y = 0; y < H; y++) {
      if (F[x][y]) continue;
      ans++;

      // 幅優先探索
      queue<P> que;
      que.push(make_pair(x, y));
      while (!que.empty()) {
        int sx = que.front().first;
        int sy = que.front().second;
        que.pop();

        rep(i, 4) {
          int tx = sx + dx[i];
          int ty = sy + dy[i];
          if (tx < 0 || W <= tx || ty < 0 || H <= ty) continue;
          if (F[tx][ty]) continue;
          que.push(make_pair(tx, ty));
          F[tx][ty] = true;
        }
      }
    }
  }

  cout << ans << endl;
}