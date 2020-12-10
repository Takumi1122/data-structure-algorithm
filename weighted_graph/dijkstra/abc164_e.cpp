#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 拡張ダイクストラ法
// グラフの各頂点に、所持金の情報も持たせる
// 頂点数: O(N * MAX)
// 辺数: O(M * MAX + N * MAX)

/*
    参考リンク
    ABC 164 E - Two Currencies
      https://atcoder.jp/contests/abc164/tasks/abc164_e
*/

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

using pll = pair<ll, ll>;  // (money, time)
using Edge = pair<int, pll>;
using Graph = vector<vector<Edge>>;
const ll INF = 1LL << 60;
const int MAX = 2500;

int n, m;
ll s;
Graph G;
vector<ll> c, d;  // money, time

void solve() {
  if (s >= MAX) s = MAX;
  // dp[v][s]:頂点vにいて、所持金sという状態になるのに要する最小の所要時間
  vector<vector<ll>> dp(n, vector<ll>(MAX + 1, INF));

  priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>>>
      que;
  dp[0][s] = 0;
  // que.push(時間, pll(頂点, 所持金))
  que.push(make_pair(0, pll(0, s)));
  while (!que.empty()) {
    auto p = que.top();
    que.pop();
    ll time = p.first;
    int v = p.second.first;
    ll s = p.second.second;
    if (time > dp[v][s]) continue;

    // 補充
    if (s + c[v] <= MAX) {
      ll ns = s + c[v];
      ll ntime = time + d[v];
      if (chmin(dp[v][ns], ntime)) {
        que.push(make_pair(ntime, pll(v, ns)));
      }
    }

    // 辺を通る
    for (auto e : G[v]) {
      // 所持金が足りない
      if (s < e.second.first) continue;

      int nv = e.first;
      ll ns = s - e.second.first;
      ll ntime = time + e.second.second;
      if (chmin(dp[nv][ns], ntime)) {
        que.push(make_pair(ntime, pll(nv, ns)));
      }
    }
  }

  for (int v = 1; v < n; ++v) {
    ll res = INF;
    for (int s = 0; s <= MAX; ++s) chmin(res, dp[v][s]);
    cout << res << endl;
  }
}

int main() {
  cin >> n >> m >> s;
  G.assign(n, vector<Edge>());

  rep(i, m) {
    ll u, v, a, b;
    cin >> u >> v >> a >> b;
    --u, --v;
    G[u].push_back(Edge(v, pll(a, b)));
    G[v].push_back(Edge(u, pll(a, b)));
  }

  c.resize(n);
  d.resize(n);

  rep(i, n) cin >> c[i] >> d[i];
  solve();
}