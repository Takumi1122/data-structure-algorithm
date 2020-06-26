#include <iostream>
#include <vector>
using namespace std;

struct Edge {
  int to;      // 辺の行き先
  int weight;  // 辺の重み
  Edge(int t, int w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;

int main() {
  // 頂点数と辺数
  int N, M;
  cin >> N >> M;

  // グラフ
  Graph G(N);
  for (int i = 0; i < M; ++i) {
    int from, to, weight;
    cin >> from >> to >> weight;
    G[from].push_back(Edge(to, weight));
  }
}