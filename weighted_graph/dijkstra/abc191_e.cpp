#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// n頂点それぞれでダイクストラ法 O(N*(N+M)log(N))
// 1本以上の道路を通り，出発した町に帰ってくるような経路

/*
    参考リンク
    ABC 191 E - Come Back Quickly
      https://atcoder.jp/contests/abc191/tasks/abc191_e
*/

struct E {
  int to, co;
  E(int to = 0, int co = 0) : to(to), co(co) {}
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<E>> g(n);
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    --a;
    --b;
    g[a].emplace_back(b, c);
  }

  const int INF = 1001001001;
  rep(sv, n) {
    vector<int> dist(n, INF);
    priority_queue<P, vector<P>, greater<P>> q;

    auto push = [&](int v, int d) {
      if (dist[v] <= d) return;
      dist[v] = d;
      q.emplace(d, v);
    };
    // 最初に使う辺の候補
    for (auto&& e : g[sv]) push(e.to, e.co);

    while (!q.empty()) {
      int d = q.top().first;
      int v = q.top().second;
      q.pop();
      if (dist[v] != d) continue;
      for (auto&& e : g[v]) {
        push(e.to, d + e.co);
      }
    }

    int ans = dist[sv];
    if (ans == INF) ans = -1;
    cout << ans << endl;
  }
  return 0;
}