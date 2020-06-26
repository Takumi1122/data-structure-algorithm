#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

using pll = pair<long long, long long>;  // (money, time)
using Edge = pair<int, pll>;
using Graph = vector<vector<Edge>>;
const long long INF = 1LL << 60;
const int MAX = 2500;

int N, M;
long long S;
Graph G;
vector<long long> C, D;  // money, time

void solve() {
  if (S >= MAX) S = MAX;
  vector<vector<long long>> dp(N, vector<long long>(MAX + 1, INF));
  priority_queue<pair<long long, pll>, vector<pair<long long, pll>>,
                 greater<pair<long long, pll>>>
      que;
  dp[0][S] = 0;
  que.push(make_pair(0, pll(0, S)));
  while (!que.empty()) {
    auto p = que.top();
    que.pop();
    long long time = p.first;
    int v = p.second.first;
    long long s = p.second.second;
    if (time > dp[v][s]) continue;

    // 補充
    if (s + C[v] <= MAX) {
      long long ns = s + C[v];
      long long ntime = time + D[v];
      if (chmin(dp[v][ns], ntime)) {
        que.push(make_pair(ntime, pll(v, ns)));
      }
    }
    // 辺を通る
    for (auto e : G[v]) {
      if (s < e.second.first) continue;
      int nv = e.first;
      long long ns = s - e.second.first;
      long long ntime = time + e.second.second;
      if (chmin(dp[nv][ns], ntime)) {
        que.push(make_pair(ntime, pll(nv, ns)));
      }
    }
  }
  for (int v = 1; v < N; ++v) {
    long long res = INF;
    for (int s = 0; s <= MAX; ++s) chmin(res, dp[v][s]);
    cout << res << endl;
  }
}

int main() {
  cin >> N >> M >> S;
  G.assign(N, vector<Edge>());
  for (int i = 0; i < M; ++i) {
    long long u, v, a, b;
    cin >> u >> v >> a >> b;
    --u, --v;
    G[u].push_back(Edge(v, pll(a, b)));
    G[v].push_back(Edge(u, pll(a, b)));
  }
  C.resize(N);
  D.resize(N);
  for (int i = 0; i < N; ++i) cin >> C[i] >> D[i];
  solve();
}