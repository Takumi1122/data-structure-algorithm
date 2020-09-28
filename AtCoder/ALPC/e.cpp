#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

#include <atcoder/all>
using namespace atcoder;

const ll BIG = 1'000'000'000;

int main() {
  int n, k;
  cin >> n >> k;

  /**
   * generate (s -> row -> column -> t) graph
   * i-th row correspond to vertex i
   * i-th col correspond to vertex n + i
   **/
  mcf_graph<int, ll> g(2 * n + 2);
  int s = 2 * n, t = 2 * n + 1;

  // we can "waste" the flow
  g.add_edge(s, t, n * k, BIG);

  rep(i, n) {
    g.add_edge(s, i, k, 0);
    g.add_edge(n + i, t, k, 0);
  }

  rep(i, n) {
    rep(j, n) {
      ll a;
      cin >> a;
      g.add_edge(i, n + j, 1, BIG - a);
    }
  }

  auto result = g.flow(s, t, n * k);
  cout << 1LL * n * k * BIG - result.second << endl;

  vector<string> grid(n, string(n, '.'));
  auto edges = g.edges();
  for (auto e : edges) {
    if (e.from == s || e.to == t || e.flow == 0) continue;

    grid[e.from][e.to - n] = 'X';
  }

  rep(i, n) cout << grid[i] << endl;
  return 0;
}
