#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// max-flow (Dinic's algorithm)
// O(|V|^2|E|)
// 2部マッチング 最大マッチング

// 頂点数: 最大200
// 辺数: 最大10000

/*
    参考リンク
    ABC 91 C - 2D Plane 2N Points
      https://atcoder.jp/contests/abc091/tasks/arc092_a
*/

// edge class (for network-flow)
template <class FLOWTYPE>
struct Edge {
  int rev, from, to;
  FLOWTYPE cap, icap;
  Edge(int r, int f, int t, FLOWTYPE c)
      : rev(r), from(f), to(t), cap(c), icap(c) {}
  friend ostream &operator<<(ostream &s, const Edge &E) {
    if (E.cap > 0)
      return s << E.from << "->" << E.to << '(' << E.cap << ')';
    else
      return s;
  }
};

// graph class (for network-flow)
template <class FLOWTYPE>
struct Graph {
  vector<vector<Edge<FLOWTYPE> > > list;

  Graph(int n = 0) : list(n) {}
  void init(int n = 0) {
    list.clear();
    list.resize(n);
  }
  void reset() {
    for (int i = 0; i < (int)list.size(); ++i)
      for (int j = 0; j < list[i].size(); ++j) list[i][j].cap = list[i][j].icap;
  }
  inline vector<Edge<FLOWTYPE> > &operator[](int i) { return list[i]; }
  inline const size_t size() const { return list.size(); }

  inline Edge<FLOWTYPE> &redge(Edge<FLOWTYPE> e) {
    if (e.from != e.to)
      return list[e.to][e.rev];
    else
      return list[e.to][e.rev + 1];
  }

  void addedge(int from, int to, FLOWTYPE cap) {
    list[from].push_back(Edge<FLOWTYPE>((int)list[to].size(), from, to, cap));
    list[to].push_back(Edge<FLOWTYPE>((int)list[from].size() - 1, to, from, 0));
  }

  void add_undirected_edge(int from, int to, FLOWTYPE cap) {
    list[from].push_back(Edge<FLOWTYPE>((int)list[to].size(), from, to, cap));
    list[to].push_back(
        Edge<FLOWTYPE>((int)list[from].size() - 1, to, from, cap));
  }

  /*
  // debug
  friend ostream& operator << (ostream& s, const Graph& G) {
      s << endl;
      for (int i = 0; i < G.size(); ++i) {
          s << i << " : " << G.list[i] << endl;
      }
      return s;
  }
  */
};

template <class FLOWTYPE>
struct Dinic {
  const FLOWTYPE INF = 1 << 30;  // to be set
  vector<int> level, iter;

  Dinic() {}
  void dibfs(Graph<FLOWTYPE> &G, int s) {
    level.assign((int)G.size(), -1);
    level[s] = 0;
    queue<int> que;
    que.push(s);
    while (!que.empty()) {
      int v = que.front();
      que.pop();
      for (int i = 0; i < G[v].size(); ++i) {
        Edge<FLOWTYPE> &e = G[v][i];
        if (level[e.to] < 0 && e.cap > 0) {
          level[e.to] = level[v] + 1;
          que.push(e.to);
        }
      }
    }
  }

  FLOWTYPE didfs(Graph<FLOWTYPE> &G, int v, int t, FLOWTYPE f) {
    if (v == t) return f;
    for (int &i = iter[v]; i < G[v].size(); ++i) {
      Edge<FLOWTYPE> &e = G[v][i], &re = G.redge(e);
      if (level[v] < level[e.to] && e.cap > 0) {
        FLOWTYPE d = didfs(G, e.to, t, min(f, e.cap));
        if (d > 0) {
          e.cap -= d;
          re.cap += d;
          return d;
        }
      }
    }
    return 0;
  }

  FLOWTYPE solve(Graph<FLOWTYPE> &G, int s, int t) {
    level.assign((int)G.size(), -1);
    iter.assign((int)G.size(), 0);
    FLOWTYPE res = 0;
    while (true) {
      dibfs(G, s);
      if (level[t] < 0) return res;
      for (int i = 0; i < (int)iter.size(); ++i) iter[i] = 0;
      FLOWTYPE flow = 0;
      while ((flow = didfs(G, s, t, INF)) > 0) {
        res += flow;
      }
    }
  }
};

int main() {
  int n;
  cin >> n;
  Graph<int> G(2 * n + 2);

  // スーパーノード S, T の index
  int S_node = 2 * n;
  int T_node = 2 * n + 1;

  vector<int> a(n), b(n), c(n), d(n);
  rep(i, n) cin >> a[i] >> b[i];
  rep(i, n) cin >> c[i] >> d[i];

  rep(i, n) rep(j, n) {
    if (a[i] < c[j] && b[i] < d[j]) G.addedge(i, n + j, 1);
  }

  rep(i, n) G.addedge(S_node, i, 1);
  rep(j, n) G.addedge(j + n, T_node, 1);

  Dinic<int> di;
  cout << di.solve(G, S_node, T_node) << endl;
  return 0;
}