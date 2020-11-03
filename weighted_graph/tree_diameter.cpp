#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 木の直径 O(n)

/*
    参考リンク
    AIZU ONLINE JUDGE
      https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_A
*/

const int MAX = 100000;
const int INF = 1 << 30;

class Edge {
 public:
  int t, w;
  Edge() {}
  Edge(int t, int w) : t(t), w(w) {}
};

vector<Edge> G[MAX];
int n, d[MAX];

bool vis[MAX];
int cnt;

// 幅優先探索
void bfs(int s) {
  rep(i, n) d[i] = INF;
  queue<int> q;
  q.push(s);
  d[s] = 0;
  int u;
  while (!q.empty()) {
    u = q.front();
    q.pop();
    for (auto e : G[u]) {
      if (d[e.t] == INF) {
        d[e.t] = d[u] + e.w;
        q.push(e.t);
      }
    }
  }
}

void solve() {
  // 適当な始点 s から最も遠い節点 tgt　を求める
  bfs(0);
  int maxv = 0;
  int tgt = 0;
  rep(i, n) {
    if (d[i] == INF) continue;
    if (maxv < d[i]) {
      maxv = d[i];
      tgt = i;
    }
  }

  // tgt から最も遠い節点の距離 maxv を求める
  bfs(tgt);
  maxv = 0;
  rep(i, n) {
    if (d[i] == INF) continue;
    maxv = max(maxv, d[i]);
  }

  cout << maxv << endl;
}

int main() {
  cin >> n;

  rep(i, n - 1) {
    int s, t, w;
    cin >> s >> t >> w;
    G[s].push_back(Edge(t, w));
    G[t].push_back(Edge(s, w));
  }

  solve();
}