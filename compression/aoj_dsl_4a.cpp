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

/*
    参考リンク
    AIZU ONLINE JUDGE
      https://onlinejudge.u-aizu.ac.jp/problems/DSL_4_A
*/

template <class T>
vector<T> compress(vector<T> &C1, vector<T> &C2) {
  vector<T> vals;
  int n = (int)C1.size();
  rep(i, n) {
    // その位置と、一つ隣を確保(隣を確保しないと空白が埋まってしまうことがある)
    for (T d = 0; d <= 1; d++) {
      T tc1 = C1[i] + d;
      T tc2 = C2[i] + d;
      vals.push_back(tc1);
      vals.push_back(tc2);
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

int main() {
  // 入力
  int n;
  cin >> n;
  vector<ll> x1(n), y1(n), x2(n), y2(n);
  rep(i, n) cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];

  // 座標圧縮
  vector<ll> X = compress(x1, x2);
  vector<ll> Y = compress(y1, y2);

  // imos法で塗りつぶし
  int w = (int)X.size();
  int h = (int)Y.size();
  vector<vector<int>> G(w, vector<int>(h));
  rep(i, n) {
    G[x1[i]][y1[i]]++;
    G[x2[i]][y2[i]]++;
    G[x1[i]][y2[i]]--;
    G[x2[i]][y1[i]]--;
  }
  for (int x = 1; x < w; x++) {
    for (int y = 0; y < h; y++) {
      G[x][y] += G[x - 1][y];
    }
  }
  for (int x = 0; x < w; x++) {
    for (int y = 1; y < h; y++) {
      G[x][y] += G[x][y - 1];
    }
  }

  // 塗りつぶしたマスの面積を全て足し合わせる
  ll ans = 0;
  for (int x = 0; x < w - 1; x++) {
    for (int y = 0; y < h - 1; y++) {
      if (G[x][y]) {
        ans += (X[x + 1] - X[x]) * (Y[y + 1] - Y[y]);
      }
    }
  }

  cout << ans << endl;
}