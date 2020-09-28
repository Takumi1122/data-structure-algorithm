#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

#include <atcoder/all>
using namespace atcoder;

int main() {
  int n, m;
  cin >> n >> m;

  scc_graph g(n);

  rep(i, m) {
    int u, v;
    cin >> u >> v;
    g.add_edge(u, v);
  }

  auto scc = g.scc();

  cout << int(scc.size()) << endl;
  for (auto v : scc) {
    cout << int(v.size()) << endl;
    for (int x : v) {
      cout << x << endl;
    }
  }

  return 0;
}
