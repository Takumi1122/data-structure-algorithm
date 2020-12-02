#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

struct Edge {
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;

int main() {
  int n, m;
  cin >> n >> m;

  Graph G(n);
  rep(i, m) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    G[u].push_back(Edge(v, w));
  }
}