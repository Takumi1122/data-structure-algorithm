#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// トポロジカルソートする
void rec(int v, const Graph &G, vector<bool> &seen, vector<int> &order) {
  seen[v] = true;
  for (auto next : G[v]) {
    if (seen[next]) continue;
    rec(next, G, seen, order);
  }
  order.push_back(v);
}

int main() {
  int n, m;
  cin >> n >> m;
  Graph G(n);

  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
  }

  vector<bool> seen(n, 0);
  vector<int> order;  // トポロジカルソート順
  rep(v, n) {
    if (seen[v]) continue;
    rec(v, G, seen, order);
  }

  reverse(order.begin(), order.end());

  for (auto v : order) cout << v << " -> ";
  cout << endl;
}