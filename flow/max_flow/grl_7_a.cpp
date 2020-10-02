#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// max-flow (Ford-Fulkerson algorithm)
// 計算量	O(FE) F: = 最大流の流量 E: = 辺の数
// 2部マッチング

/*
    参考リンク
    AIZU ONLINE JUDGE
      https://onlinejudge.u-aizu.ac.jp/problems/GRL_7_A
*/

// edge class (for network-flow)
template <class FLOWTYPE>
struct Edge {
  int rev, from, to;
  FLOWTYPE cap, icap;
  Edge(int r, int f, int t, FLOWTYPE c)
      : rev(r), from(f), to(t), cap(c), icap(c) {}
  friend ostream& operator<<(ostream& s, const Edge& E) {
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
  inline vector<Edge<FLOWTYPE> >& operator[](int i) { return list[i]; }
  inline const size_t size() const { return list.size(); }

  inline Edge<FLOWTYPE>& redge(Edge<FLOWTYPE> e) {
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
struct FordFulkerson {
  const FLOWTYPE INF = 1 << 30;  // to be set
  vector<int> used;

  FordFulkerson() {}
  FLOWTYPE fodfs(Graph<FLOWTYPE>& G, int v, int t, FLOWTYPE f) {
    if (v == t) return f;
    used[v] = true;
    for (auto& e : G[v]) {
      if (!used[e.to] && e.cap > 0) {
        int d = fodfs(G, e.to, t, min(f, e.cap));
        if (d > 0) {
          e.cap -= d;
          G.redge(e).cap += d;
          return d;
        }
      }
    }
    return 0;
  }
  FLOWTYPE solve(Graph<FLOWTYPE>& G, int s, int t) {
    FLOWTYPE res = 0;
    while (true) {
      used.assign((int)G.size(), 0);
      int flow = fodfs(G, s, t, INF);
      if (flow == 0)
        return res;
      else
        res += flow;
    }
    return 0;
  }
};

int main() {
  int X, Y, E;
  cin >> X >> Y >> E;
  Graph<int> G(X + Y + 2);

  // スーパーノード S, T の index
  int S_node = X + Y;
  int T_node = X + Y + 1;

  rep(i, E) {
    int x, y;
    cin >> x >> y;
    G.addedge(x, y + X, 1);
  }

  rep(i, X) G.addedge(S_node, i, 1);

  rep(j, Y) G.addedge(j + X, T_node, 1);

  FordFulkerson<int> ff;
  cout << ff.solve(G, S_node, T_node) << endl;
}