#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 包除原理

/*
    参考リンク
    ABC 152 F - Tree and Constraints
      https://atcoder.jp/contests/abc152/tasks/abc152_f
*/

struct Edge {
  int to, id;
  Edge(int to, int id) : to(to), id(id) {}
};

vector<Edge> g[55];

vector<int> es;
bool dfs(int v, int tv, int p = -1) {
  if (v == tv) return true;
  for (Edge e : g[v]) {
    if (e.to == p) continue;
    if (dfs(e.to, tv, v)) {
      es.push_back(e.id);
      return true;
    }
  }
  return false;
}

int main() {
  int n, m;
  cin >> n;
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    g[a].emplace_back(b, i);
    g[b].emplace_back(a, i);
  }

  cin >> m;
  vector<ll> eset(m);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    es = vector<int>();
    dfs(a, b);
    for (int e : es) {
      eset[i] |= 1ll << e;
    }
  }

  ll ans = 0;
  rep(i, 1 << m) {
    ll mask = 0;
    rep(j, m) {
      if (i >> j & 1) mask |= eset[j];
    }
    int white = __builtin_popcountll(mask);
    ll now = 1ll << (n - 1 - white);  // 2^(n-1-white)
    if (__builtin_popcountll(i) % 2 == 0)
      ans += now;
    else
      ans -= now;
  }

  cout << ans << endl;
  return 0;
}