#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// BFS はそもそも始点sから各頂点vへの最短路を求めるアルゴリズム

/*
    参考リンク
    ABC 168 D - .. (Double Dots)
      https://atcoder.jp/contests/abc168/tasks/abc168_d
*/

int main() {
  int n, m;
  cin >> n >> m;

  Graph G(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  vector<int> dist(n, -1);
  vector<int> pre(n, -1);
  queue<int> que;

  dist[0] = 0;
  que.push(0);

  while (!que.empty()) {
    int v = que.front();
    que.pop();

    for (int nv : G[v]) {
      if (dist[nv] != -1) continue;

      dist[nv] = dist[v] + 1;
      pre[nv] = v + 1;
      que.push(nv);
    }
  }

  rep(i, n - 1) {
    if (pre[i + 1] == -1) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  rep(i, n - 1) { cout << pre[i + 1] << endl; }

  return 0;
}