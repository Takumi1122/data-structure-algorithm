#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// サイクル検出

/*
    参考リンク
    AIZU ONLINE JUDGE
      https://onlinejudge.u-aizu.ac.jp/problems/2891
*/

int main() {
  // 頂点数 (サイクルを一つ含むグラフなので辺数は N で確定)
  int n;
  cin >> n;

  // グラフ入力受取
  Graph G(n);
  vector<int> deg(n, 0);  // 各頂点の出次数
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    --a, --b;  // 0-indexed にする
    G[a].push_back(b);
    G[b].push_back(a);
    ++deg[a], ++deg[b];
  }

  // 葉たちをキューに挿入する
  // 今回は無向グラフなので、deg[v] == 1 が葉の条件になります
  queue<int> que;
  rep(v, n) if (deg[v] == 1) que.push(v);

  // 探索
  vector<bool> ispushed(n, false);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    ispushed[v] = true;
    for (auto nv : G[v]) {
      --deg[nv];
      if (deg[nv] == 1) que.push(nv);
    }
  }

  // クエリに答える
  int q;
  cin >> q;
  for (int _ = 0; _ < q; ++_) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    if (!ispushed[a] && !ispushed[b])
      cout << 2 << endl;
    else
      cout << 1 << endl;
  }
}  
