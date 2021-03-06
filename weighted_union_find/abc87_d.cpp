#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 重み付きUnionFind
// 差分制約に使用 x[ri] - x[li] = di
// root の重みは0

/*
    参考リンク
    ABC 87 D - People on a Line
      https://atcoder.jp/contests/abc087/tasks/arc090_b
*/

template <class Abel>
struct UnionFind {
  vector<int> par;
  vector<int> rank;
  vector<Abel> diff_weight;

  UnionFind(int n = 1, Abel SUM_UNITY = 0) { init(n, SUM_UNITY); }

  void init(int n = 1, Abel SUM_UNITY = 0) {
    par.resize(n);
    rank.resize(n);
    diff_weight.resize(n);
    rep(i, n) par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
  }

  int root(int x) {
    if (par[x] == x) {
      return x;
    } else {
      int r = root(par[x]);
      diff_weight[x] += diff_weight[par[x]];
      return par[x] = r;
    }
  }

  Abel weight(int x) {
    root(x);
    return diff_weight[x];
  }

  // x と y が同じグループにいるかどうかを判定する
  bool issame(int x, int y) { return root(x) == root(y); }

  // weight(y) = weight(x) + w となるように x と y をマージする
  bool merge(int x, int y, Abel w) {
    w += weight(x);
    w -= weight(y);
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (rank[x] < rank[y]) swap(x, y), w = -w;
    if (rank[x] == rank[y]) ++rank[x];
    par[y] = x;
    diff_weight[y] = w;
    return true;
  }

  // x と y とが同じグループにいるとき、weight(y) - weight(x) をリターンする
  Abel diff(int x, int y) { return weight(y) - weight(x); }
};

int main() {
  int n, m;
  cin >> n >> m;
  UnionFind<int> uf(n);

  rep(i, m) {
    int l, r, d;
    cin >> l >> r >> d;
    --l, --r;
    if (uf.issame(l, r)) {
      int diff = uf.diff(l, r);
      if (diff != d) {
        cout << "No" << endl;
        return 0;
      }
    } else {
      uf.merge(l, r, d);
    }
  }
  cout << "Yes" << endl;
  return 0;
}