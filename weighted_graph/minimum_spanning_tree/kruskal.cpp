#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define MAX 10000
#define INFTY (1 << 29)

// o(|E|log|E|)

class DisjointSet {
 public:
  // rank[x] ノードxを根としたときの木の高さ
  vector<int> rank, p;

  DisjointSet() {}
  DisjointSet(int size) {
    rank.resize(size, 0);
    p.resize(size, 0);
    rep(i, size) makeSet(i);
  }

  void makeSet(int x) {
    p[x] = x;
    rank[x] = 0;
  }

  bool same(int x, int y) { return findSet(x) == findSet(y); }

  void unite(int x, int y) { link(findSet(x), findSet(y)); }

  void link(int x, int y) {
    if (rank[x] > rank[y]) {
      p[y] = x;
    } else {
      p[x] = y;
      if (rank[x] == rank[y]) {
        rank[y]++;
      }
    }
  }

  int findSet(int x) {
    if (x != p[x]) {
      p[x] = findSet(p[x]);
    }
    return p[x];
  }
};

class Edge {
 public:
  int source, target, cost;
  Edge(int source = 0, int target = 0, int cost = 0)
      : source(source), target(target), cost(cost) {}
  bool operator<(const Edge &e) const { return cost < e.cost; }
};

int kruskal(int n, vector<Edge> edges) {
  int totalCost = 0;
  sort(edges.begin(), edges.end());

  DisjointSet dset = DisjointSet(n + 1);

  rep(i, n) dset.makeSet(i);

  int source, target;
  rep(i, edges.size()) {
    Edge e = edges[i];
    if (!dset.same(e.source, e.target)) {
      totalCost += e.cost;
      dset.unite(e.source, e.target);
    }
  }
  return totalCost;
}

int main() {
  // n: 頂点数
  // m: 辺の数
  int n, m, cost;
  int source, target;

  cin >> n >> m;

  vector<Edge> edges;
  rep(i, m) {
    cin >> source >> target >> cost;
    edges.push_back(Edge(source, target, cost));
  }

  cout << kruskal(n, edges) << endl;
}