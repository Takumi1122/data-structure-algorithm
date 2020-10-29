#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

//　蟻本P295: Housewife Wind

struct Edge {
  int index;
  int to;
  int weight;
  Edge(int i, int t, int w) : index(i), to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;

template <class Abel>
struct BIT {
  vector<Abel> dat;
  Abel UNITY_SUM = 0;  // to be set

  /* [1, n] */
  BIT(int n) { init(n); }
  void init(int n) {
    dat.resize(n + 1);
    for (int i = 0; i < (int)dat.size(); ++i) dat[i] = UNITY_SUM;
  }

  /* a is 1-indexed */
  inline void add(int a, Abel x) {
    for (int i = a; i < (int)dat.size(); i += i & -i) dat[i] = dat[i] + x;
  }

  /* [1, a], a is 1-indexed */
  inline Abel sum(int a) {
    Abel res = UNITY_SUM;
    for (int i = a; i > 0; i -= i & -i) res = res + dat[i];
    return res;
  }

  /* [a, b), a and b are 1-indexed */
  inline Abel sum(int a, int b) { return sum(b - 1) - sum(a - 1); }

  /* k-th number (k is 0-indexed) */
  int get(long long k) {
    ++k;
    int res = 0;
    int N = 1;
    while (N < (int)dat.size()) N *= 2;
    for (int i = N / 2; i > 0; i /= 2) {
      if (res + i < (int)dat.size() && dat[res + i] < k) {
        k = k - dat[res + i];
        res = res + i;
      }
    }
    return res + 1;
  }
};

class LCA {
 public:
  int n, segn;
  vector<int> path, depth, in_order;
  vector<pair<int, int>> dat;
  const pair<int, int> INF = make_pair(1000000000, 1000000000);
  vector<int> es;
  BIT<int> bit;

  LCA(const Graph &g, int root)
      : n(g.size()),
        path(n * 2 - 1),
        depth(n * 2 - 1),
        in_order(n),
        es(n * 2 - 2),
        bit(n) {
    int k = 0;
    dfs(g, root, -1, 0, k);
    for (segn = 1; segn < n * 2 - 1; segn <<= 1)
      ;
    dat.assign(segn * 2, INF);
    for (int i = 0; i < (int)depth.size(); ++i)
      dat[segn + i] = make_pair(depth[i], i);
    for (int i = segn - 1; i >= 1; --i)
      dat[i] = min(dat[i * 2], dat[i * 2 + 1]);
  }

  int get(int u, int v) const {
    int l = min(in_order[u], in_order[v]);
    int r = max(in_order[u], in_order[v]) + 1;
    return path[range_min(1, segn, l, r).second];
  }

  void dfs(const Graph &g, int v, int p, int d, int &k) {
    in_order[v] = k;
    path[k] = v;
    depth[k++] = d;
    for (auto &e : g[v]) {
      if (e.to != p) {
        bit.add(k, e.weight);
        es[e.index * 2] = k;
        dfs(g, e.to, v, d + 1, k);
        path[k] = v;
        depth[k++] = d;
        bit.add(k, -e.weight);
        es[e.index * 2 + 1] = k;
      }
    }
  }

  pair<int, int> range_min(int v, int w, int l, int r) const {
    if (r <= l || w == 0) return INF;
    if (r - l == w) return dat[v];
    int m = w / 2;
    auto rmin = range_min(v * 2, m, l, min(r, m));
    auto lmin = range_min(v * 2 + 1, m, max(0, l - m), r - m);
    return min(rmin, lmin);
  }
};

int main() {
  int n, q, s;
  cin >> n >> q >> s;
  Graph G(n);
  vector<int> weight(n - 1);
  rep(i, n - 1) {
    int a, b, w;
    cin >> a >> b >> w;
    a--;
    b--;
    G[a].push_back(Edge(i, b, w));
    G[b].push_back(Edge(i, a, w));
    weight[i] = w;
  }

  s--;
  LCA lca(G, s);
  int v = s;
  rep(i, q) {
    int type;
    cin >> type;
    if (type == 0) {
      int x;
      cin >> x;
      x--;
      int p = lca.get(v, x);
      int ans = lca.bit.sum(lca.in_order[x]) + lca.bit.sum(lca.in_order[v]) -
                lca.bit.sum(lca.in_order[p]) * 2;
      cout << ans << endl;
      v = x;
    } else {
      int x, t;
      cin >> x >> t;
      x--;
      lca.bit.add(lca.es[x * 2], t - weight[x]);
      lca.bit.add(lca.es[x * 2 + 1], weight[x] - t);
      weight[x] = t;
    }
  }
}