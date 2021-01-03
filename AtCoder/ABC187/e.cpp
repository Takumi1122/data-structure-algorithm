#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 木でいもす法

/*
    参考リンク
    ABC 187 E - Through Path
      https://atcoder.jp/contests/abc187/tasks/abc187_e
*/

int main() {
  int n;
  cin >> n;
  Graph g(n);
  vector<P> edge(n - 1);
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
    edge[i] = {a, b};
  }

  vector<int> dist(n, -1);
  queue<int> que;
  dist[0] = 0;
  que.push(0);
  while (!que.empty()) {
    int v = que.front();
    que.pop();

    for (int nv : g[v]) {
      if (dist[nv] != -1) continue;
      dist[nv] = dist[v] + 1;
      que.push(nv);
    }
  }

  vector<ll> ans(n);
  int q;
  cin >> q;
  rep(i, q) {
    int t, e, x;
    cin >> t >> e >> x;
    e--;
    int a = edge[e].first;
    int b = edge[e].second;
    if (dist[a] > dist[b]) {
      swap(a, b);
      t ^= 3;
    }
    if (t == 1) {
      ans[0] += x;
      ans[b] -= x;
    } else
      ans[b] += x;
  }

  que.push(0);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (int nv : g[v])
      if (dist[v] < dist[nv]) {
        ans[nv] += ans[v];
        que.push(nv);
      }
  }

  rep(i, n) cout << ans[i] << endl;
  return 0;
}