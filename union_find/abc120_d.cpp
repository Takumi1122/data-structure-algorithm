#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// クエリを先読みしておいて逆順に処理
// 操作を逆順に見る
// 「辺を削除する」というのはめちゃくちゃ扱いづらいので,反対に「辺を追加する」と読み替えた方がいい

/*
    参考リンク
    ABC 120 D - Decayed Bridges
      https://atcoder.jp/contests/abc120/tasks/abc120_d
*/

struct UnionFind {
  vector<int> par;

  UnionFind(int n) : par(n, -1) {}

  int root(int x) {
    if (par[x] < 0)
      return x;
    else
      return par[x] = root(par[x]);
  }

  bool issame(int x, int y) { return root(x) == root(y); }

  bool merge(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (par[x] > par[y]) swap(x, y);  // merge technique
    par[x] += par[y];
    par[y] = x;
    return true;
  }

  int size(int x) { return -par[root(x)]; }
};

int main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(m), b(m);
  rep(i, m) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }

  UnionFind uf(n);
  ll now = n * (n - 1) / 2;
  vector<ll> ans;
  rep(i, m) {
    ans.push_back(now);

    int ai = a[m - 1 - i];
    int bi = b[m - 1 - i];
    if (uf.issame(ai, bi)) continue;

    ll sa = uf.size(ai);
    ll sb = uf.size(bi);
    now -= sa * sb;
    uf.merge(ai, bi);
  }

  reverse(ans.begin(), ans.end());
  rep(i, m) cout << ans[i] << endl;
  return 0;
}