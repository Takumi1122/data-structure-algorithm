#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<P>>;

/*  
    // 辺彩色
    グラフの辺を彩色するもので、1つの頂点に接合するそれぞれの辺が常に別々の色になるように最適彩色

    ・グラフが木ならば、「最大次数」で辺を彩色できる
    ・一般のグラフの場合は最大次数色では塗りきれないケースが存在 (最大次数色 + 1 で塗ることは可能)
*/

/*
    参考リンク
    ABC 146 D - Coloring Edges on Tree
      https://atcoder.jp/contests/abc146/tasks/abc146_d
*/

int main() {
  int n;
  cin >> n;

  Graph G(n);
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].emplace_back(b, i);
    G[b].emplace_back(a, i);
  }

  int max_color = 0;
  rep(i, n) {
    int size = G[i].size();
    max_color = max(max_color, size);
  }

  vector<int> res(n - 1, -1);
  vector<int> dist(n, -1);
  queue<P> que;

  dist[0] = 0;
  que.push({0, -1});  // (頂点, 前回の色)

  while (!que.empty()) {
    auto p = que.front();
    que.pop();
    int v = p.first, c = p.second;
    int color = 1;
    if (color == c) ++color;

    for (auto e : G[v]) {
      if (dist[e.first] != -1) continue;

      dist[e.first] = dist[v] + 1;
      que.push({e.first, color});
      res[e.second] = color;
      ++color;
      if (color == c) ++color;
    }
  }

  cout << max_color << endl;
  for (auto v : res) cout << v << endl;
}