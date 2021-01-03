#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 木上のクエリを処理する問題では、「まずは配列について考える」
// 配列は「枝分かれのない木」なので、木の特殊ケースとみなせる

/*
    参考リンク
    ABC 138 D - Ki
      https://atcoder.jp/contests/abc138/tasks/abc138_d
*/

int main() {
  int n, q;
  cin >> n >> q;
  vector<ll> ans(n);

  Graph G(n);
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  rep(i, q) {
    int p, x;
    cin >> p >> x;
    p--;
    ans[p] += x;
  }

  vector<int> dist(n, -1);
  queue<int> que;

  dist[0] = 0;
  que.push(0);

  while (!que.empty()) {
    int v = que.front();
    que.pop();

    for (int nv : G[v]) {
      if (dist[nv] != -1) continue;

      dist[nv] = dist[v] + 1;
      que.push(nv);
      ans[nv] += ans[v];
    }
  }

  rep(i, n) cout << ans[i] << endl;
}