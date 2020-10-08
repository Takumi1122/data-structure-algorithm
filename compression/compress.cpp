#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    // 座標圧縮
    X を座標圧縮して書き換える（副作用）
    返り値: ソート済みの値
    計算量: O(n * log(n))
*/

template <class T>
vector<T> compress(vector<T> &x) {
  // ソートした結果を vals に
  vector<T> vals = x;
  sort(vals.begin(), vals.end());

  // 隣り合う重複を削除(unique), 末端のゴミを削除(erase)
  vals.erase(unique(vals.begin(), vals.end()), vals.end());

  // 各要素ごとに二分探索で位置を求める
  rep(i, (int)x.size()) x[i] =
      lower_bound(vals.begin(), vals.end(), x[i]) - vals.begin();

  return vals;
}