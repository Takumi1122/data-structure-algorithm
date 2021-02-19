#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// O(V + E) 木の関節点
// 連結グラフGにおいて、頂点uと、uから出ている全ての辺を削除して得られる部分グラフが、
// 非連結になるとき、頂点uをグラフGの関節点と言います

/*
    参考リンク
    AIZU ONLINE JUDGE
      https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_A
*/

const int MAX = 100000;

vector<int> G[MAX];
int n, m;
bool visited[MAX];
int prenum[MAX], parent[MAX], lowest[MAX], timer;

void dfs(int now, int prev) {
  // ノード now を訪問した直後の処理
  prenum[now] = lowest[now] = timer;
  timer++;
  visited[now] = true;

  int next;
  rep(i, G[now].size()) {
    next = G[now][i];
    if (!visited[next]) {
      // ノード now からノード next へ訪問する直前の処理
      parent[next] = now;

      dfs(next, now);

      // ノード next の探索が終了した直後の処理
      lowest[now] = min(lowest[now], lowest[next]);
    } else if (next != prev) {
      // エッジ now --> next が Back-edge の場合の処理
      lowest[now] = min(lowest[now], prenum[next]);
    }
  }
  // ノード now の探索が終了した直後の処理
}

void art_points() {
  timer = 1;
  // lowest の計算
  dfs(0, -1);  // 0 == root

  set<int> ap;
  int np = 0;
  for (int i = 1; i < n; i++) {
    int p = parent[i];
    if (p == 0)
      np++;
    else if (prenum[p] <= lowest[i])
      ap.insert(p);
  }
  if (np > 1) ap.insert(0);

  for (auto it : ap) cout << it << endl;
}

int main() {
  cin >> n >> m;

  rep(i, m) {
    int s, t;
    cin >> s >> t;
    G[s].push_back(t);
    G[t].push_back(s);
  }
  art_points();

  return 0;
}