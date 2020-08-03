#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

// ワーシャルフロイド法 o(|V|^3)

const int INF = 1001001001;

int main() {
  int n, m, l;
  cin >> n >> m >> l;
  vector<vector<int>> dist(n, vector<int>(n, INF));
  rep(i, n) dist[i][i] = 0;
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    --a;
    --b;
    dist[a][b] = dist[b][a] = c;
  }

  rep(k, n) rep(i, n) rep(j, n) chmin(dist[i][j], dist[i][k] + dist[k][j]);
  vector<vector<int>> dist2(n, vector<int>(n, INF));
  rep(i, n) rep(j, n) {
    if (dist[i][j] <= l) dist2[i][j] = 1;
  }
  rep(k, n) rep(i, n) rep(j, n) chmin(dist2[i][j], dist2[i][k] + dist2[k][j]);

  int q;
  cin >> q;
  rep(qi, q) {
    int s, t;
    cin >> s >> t;
    --s;
    --t;
    int ans = dist2[s][t] - 1;
    if (dist2[s][t] == INF) ans = -1;
    cout << ans << endl;
  }
  return 0;
}
