#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

/*
    参考リンク
    ARC 106 B - Values
      https://atcoder.jp/contests/arc106/tasks/arc106_b
*/

int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  vector<ll> b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  Graph G(n);

  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  vector<ll> ab(n);
  rep(i, n) ab[i] = a[i] - b[i];

  // 頂点 s をスタートとした探索
  vector<int> dist(n, -1);
  queue<int> que;
  rep(v, n) {
    if (dist[v] != -1) continue;  // v が探索済みならスルー
    dist[v] = 0, que.push(v);
    ll sum = ab[v];
    while (!que.empty()) {
      int v = que.front();
      que.pop();
      for (auto nv : G[v]) {
        if (dist[nv] == -1) {
          dist[nv] = dist[v] + 1;
          sum += ab[nv];
          que.push(nv);
        }
      }
    }
    if (sum != 0) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}