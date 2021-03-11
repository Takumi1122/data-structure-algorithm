#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 頂点1を始点として、全ての頂点を1度だけ訪れるパスは何通りありますか

/*
    参考リンク
    ABC 54 C - One-stroke Path
      https://atcoder.jp/contests/abc054/tasks/abc054_c
*/

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> dist(n, vector<int>(n, 0));
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    dist[a][b] = 1;
    dist[b][a] = 1;
  }

  vector<int> order;
  for (int i = 1; i < n; ++i) order.push_back(i);

  int ans = 0;
  do {
    bool ok = true;
    if (dist[0][order[0]] == 0) ok = false;
    rep(i, n - 2) {
      if (dist[order[i]][order[i + 1]] == 0) ok = false;
    }
    if (ok) ans++;
  } while (next_permutation(order.begin(), order.end()));

  cout << ans << endl;
  return 0;
}