#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

// データ構造をマージする一般テク O(n(log(n))^2)
// 各クラスに属する生徒が何人いるかをmapやdictのようなデータ構造で持つ
// 小さい方から大きい方へ移す

/*
    参考リンク
    ABC 183 F - Confluence
      https://atcoder.jp/contests/abc183/tasks/abc183_f
*/

struct UnionFind {
  vector<int> par;
  vector<map<int, int>> mp;
  UnionFind(int n = 0) : par(n, -1), mp(n) {}
  int find(int x) {
    if (par[x] < 0) return x;
    return par[x] = find(par[x]);
  }
  bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (par[x] > par[y]) swap(x, y);
    // x > y
    for (auto p : mp[y]) {
      mp[x][p.first] += p.second;
    }
    mp[y] = map<int, int>();
    par[x] += par[y];
    par[y] = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y); }
  int size(int x) { return -par[find(x)]; }
};

int main() {
  int n, q;
  cin >> n >> q;
  UnionFind t(n);
  rep(i, n) {
    int c;
    cin >> c;
    t.mp[i][c] = 1;
  }

  rep(qi, q) {
    int type;
    cin >> type;
    if (type == 1) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      t.unite(a, b);
    } else {
      int x, y;
      cin >> x >> y;
      --x;
      x = t.find(x);
      int ans = t.mp[x][y];
      printf("%d\n", ans);
    }
  }
  return 0;
}