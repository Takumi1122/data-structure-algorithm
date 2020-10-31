#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// ワーシャル–フロイド法
// O(|V|^3)
// 全点対最短経路問題

/*
    参考リンク
    AIZU ONLINE JUDGE
      https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_C
*/

const ll INF = (1LL << 32);

int main() {
  int n, m;
  // n: 頂点数, m: 辺数
  cin >> n >> m;
  vector<vector<ll>> d(n, vector<ll>(n, 0));
  rep(i, n) rep(j, n) d[i][j] = ((i == j) ? 0 : INF);

  rep(i, m) {
    int u, v, c;
    cin >> u >> v >> c;
    d[u][v] = c;
  }

  rep(k, n) {
    rep(i, n) {
      if (d[i][k] == INF) continue;
      rep(j, n) {
        if (d[k][j] == INF) continue;
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  bool negative = false;
  rep(i, n) if (d[i][i] < 0) negative = true;

  if (negative) {
    cout << "NEGATIVE CYCLE" << endl;
  } else {
    rep(i, n) {
      rep(j, n) {
        if (j) cout << " ";
        if (d[i][j] == INF)
          cout << "INF";
        else
          cout << d[i][j];
      }
      cout << endl;
    }
  }

  return 0;
}
