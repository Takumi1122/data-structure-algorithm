#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

/*
    参考リンク
    いろはちゃんコンテスト Day2 G - 通学路
      https://atcoder.jp/contests/iroha2019-day2/tasks/iroha2019_day2_g
*/

const ll INF = 1LL << 60;
const int MAX_N = 1010;
const int MAX_K = 4000;

struct Data {
  int v, s;
  ll x;
  Data(int v, int s, ll x) : v(v), s(s), x(x) {}
  // 最小ヒープにするため逆にしている
  bool operator<(const Data& a) const { return x > a.x; }
};

vector<P> g[MAX_N];
ll cost[MAX_N][MAX_K];

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    g[a].emplace_back(b, c);
    g[b].emplace_back(a, c);
  }
  vector<int> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];

  rep(i, n) rep(j, MAX_K) cost[i][j] = INF;

  priority_queue<Data> q;
  auto push = [&](int v, int s, ll x) {
    if (s >= MAX_K) return;
    if (cost[v][s] <= x) return;
    cost[v][s] = x;
    q.emplace(v, s, x);
  };
  push(0, 0, 0);

  while (!q.empty()) {
    Data hoge = q.top();
    q.pop();
    int v = hoge.v;
    int s = hoge.s;
    ll c = hoge.x;
    if (cost[v][s] != c) continue;
    if (s < k) push(v, s + x[v], c + y[v]);
    for (auto e : g[v]) {
      push(e.first, s, c + e.second);
    }
  }

  ll ans = INF;
  rep(i, k) ans = min(ans, cost[n - 1][k + i]);
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}