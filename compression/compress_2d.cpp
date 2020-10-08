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