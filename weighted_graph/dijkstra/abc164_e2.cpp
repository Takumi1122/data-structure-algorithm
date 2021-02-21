#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 拡張ダイクストラ法
// グラフの各頂点に、所持金の情報も持たせる
// 移動に使う辺の数は最大でも N-1
// 頂点数: O(N * MAX_S)
// 辺数: O(M * MAX_S + N * MAX_S)

/*
    参考リンク
    ABC 164 E - Two Currencies
      https://atcoder.jp/contests/abc164/tasks/abc164_e
*/

const int MAX_V = 50;
const int MAX_S = MAX_V * 50 + 5;
const ll INF = 1e18;

struct Edge {
  int to, a, b;
  Edge(int to, int a, int b) : to(to), a(a), b(b) {}
};

// queueに突っ込む構造体
struct Data {
  int v, s;
  ll x;
  Data(int v, int s, ll x) : v(v), s(s), x(x) {}
  // 最小ヒープにするため逆にしている
  bool operator<(const Data& a) const { return x > a.x; }
};

vector<Edge> g[MAX_V];
ll dist[MAX_V][MAX_S + 5];

int main() {
  int n, m, s;
  cin >> n >> m >> s;
  rep(i, m) {
    int u, v, a, b;
    cin >> u >> v >> a >> b;
    --u;
    --v;
    g[u].emplace_back(v, a, b);
    g[v].emplace_back(u, a, b);
  }
  vector<int> c(n), d(n);
  rep(i, n) cin >> c[i] >> d[i];

  rep(i, n) rep(j, MAX_S + 5) dist[i][j] = INF;
  s = min(s, MAX_S);
  priority_queue<Data> q;
  auto push = [&](int v, int s, ll x) {
    if (s < 0) return;
    if (dist[v][s] <= x) return;
    dist[v][s] = x;
    q.emplace(v, s, x);
  };

  push(0, s, 0);
  while (!q.empty()) {
    Data hoge = q.top();
    q.pop();
    int v = hoge.v;
    int s = hoge.s;
    ll x = hoge.x;
    if (dist[v][s] != x) continue;
    {
      int ns = min(s + c[v], MAX_S);
      push(v, ns, x + d[v]);
    }
    for (auto e : g[v]) {
      push(e.to, s - e.a, x + e.b);
    }
  }

  for (int i = 1; i < n; ++i) {
    ll ans = INF;
    rep(j, MAX_S + 5) { ans = min(ans, dist[i][j]); }
    cout << ans << endl;
  }
  return 0;
}