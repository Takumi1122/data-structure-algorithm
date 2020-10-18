#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 180 E - Traveling Salesman among Aerial Cities
      https://atcoder.jp/contests/abc180/tasks/abc180_e
*/

const int INF = 1000100100;

template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}

int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n), z(n);
  rep(i, n) cin >> x[i] >> y[i] >> z[i];

  int n2 = 1 << n;
  vector<vector<int>> dp(n2, vector<int>(n, INF));
  vector<vector<int>> dist(n, vector<int>(n));

  rep(i, n) rep(j, n) {
    int now = abs(x[i] - x[j]);
    now += abs(y[i] - y[j]);
    now += max(0, z[j] - z[i]);
    dist[i][j] = now;
  }

  rep(i, n) {
    if (i == 0) continue;
    dp[1 << i][i] = dist[0][i];
  }

  rep(S, n2) {
    rep(v, n) {
      rep(u, n) {
        // 頂点vがSに所属していないことを確認
        if ((S & (1 << v)) == 0) {
          if (v != u) chmin(dp[S | (1 << v)][v], dp[S][u] + dist[u][v]);
        }
      }
    }
  }

  cout << dp[n2 - 1][0] << endl;
  return 0;
}