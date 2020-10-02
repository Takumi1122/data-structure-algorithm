#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

typedef int FLOW;            // フローを表す型、今回は int 型
typedef int COST;            // コストを表す型、今回は int 型
const int MAX_V = 100;       // グラフの最大ノード数
const COST INF = 100000000;  // 十分大きい値

// グラフの辺の構造体
struct Edge {
  int rev, from, to;
  FLOW cap, icap;
  COST cost;
  Edge(int r, int f, int t, FLOW ca, COST co)
      : rev(r), from(f), to(t), cap(ca), icap(ca), cost(co) {}
};

// グラフ構造体
struct Graph {
  int V;
  vector<Edge> list[MAX_V];

  Graph(int n = 0) : V(n) { rep(i, MAX_V) list[i].clear(); }
  void init(int n = 0) {
    V = n;
    rep(i, MAX_V) list[i].clear();
  }
  void resize(int n = 0) { V = n; }
  void reset() {
    rep(i, V) rep(j, list[i].size()) list[i][j].cap = list[i][j].icap;
  }
  inline vector<Edge> &operator[](int i) { return list[i]; }

  Edge &redge(Edge &e) {
    if (e.from != e.to)
      return list[e.to][e.rev];
    else
      return list[e.to][e.rev + 1];
  }

  void add_edge(int from, int to, FLOW cap, COST cost) {
    list[from].push_back(Edge((int)list[to].size(), from, to, cap, cost));
    list[to].push_back(Edge((int)list[from].size() - 1, to, from, 0, -cost));
  }
};

// 最小費用流を求める関数
COST minCostFlow(Graph &G, int s, int t, FLOW inif) {
  COST dist[MAX_V];
  int prevv[MAX_V];
  int preve[MAX_V];

  COST res = 0;
  FLOW f = inif;
  while (f > 0) {
    fill(dist, dist + G.V, INF);
    dist[s] = 0;
    while (true) {
      bool update = false;
      rep(v, G.V) {
        if (dist[v] == INF) continue;
        rep(i, G[v].size()) {
          Edge &e = G[v][i];
          if (e.cap > 0 && dist[e.to] > dist[v] + e.cost) {
            dist[e.to] = dist[v] + e.cost;
            prevv[e.to] = v;
            preve[e.to] = i;
            update = true;
          }
        }
      }
      if (!update) break;
    }

    if (dist[t] == INF) return 0;

    FLOW d = f;
    for (int v = t; v != s; v = prevv[v]) {
      d = min(d, G[prevv[v]][preve[v]].cap);
    }
    f -= d;
    res += dist[t] * d;
    for (int v = t; v != s; v = prevv[v]) {
      Edge &e = G[prevv[v]][preve[v]];
      Edge &re = G.redge(e);
      e.cap -= d;
      re.cap += d;
    }
  }
  return res;
}

int main() {
  char workers[5] = {'A', 'B', 'C', 'D', 'E'};
  int jobs[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // 従業員数と、仕事数
  int NUM_WORKER = 0, NUM_JOB = 0;
  cin >> NUM_WORKER >> NUM_JOB;

  // グラフの定義 (ノード数を引数に)
  Graph G(NUM_WORKER + NUM_JOB + 2);  // +2 は S, T の分

  // スーパーノード S, T の index
  int S_node = NUM_WORKER + NUM_JOB;
  int T_node = NUM_WORKER + NUM_JOB + 1;

  // グラフに枝を張っていく
  rep(i, NUM_WORKER) {
    rep(j, NUM_JOB) {
      int gain;
      cin >> gain;

      // 従業員 i から、仕事 j (index は j+NUM_WORKER) へと、容量 1, コスト
      // -gain の枝を張る
      G.add_edge(i, j + NUM_WORKER, 1, -gain);
    }
  }

  rep(i, NUM_WORKER) {
    // S から従業員 i へと、容量 2, コスト 0 の枝を張る
    G.add_edge(S_node, i, 2, 0);
  }

  rep(j, NUM_JOB) {
    // 仕事 j から T へと、容量 1, コスト 0 の枝を張る
    G.add_edge(j + NUM_WORKER, T_node, 1, 0);
  }

  // 最小費用流を求める
  COST res = minCostFlow(G, S_node, T_node, NUM_JOB);

  // 出力
  cout << "Max Gain: " << -res << endl;

  // 誰がどの仕事に割当てられたかを出力する
  rep(i, NUM_WORKER) {
    for (auto e : G[i]) {
      // 元々の容量 (e.icap) が 1 で、フローが流れて容量 (e.cap) が 0
      // になった部分が割り当てられたところ
      if (e.icap == 1 && e.cap == 0) {
        cout << "Worker " << workers[i] << " and "
             << "Job " << jobs[e.to - NUM_WORKER]
             << " are matched (gain: " << -e.cost << ")" << endl;
      }
    }
  }

  return 0;
}