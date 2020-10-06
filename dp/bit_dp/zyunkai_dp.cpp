#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// O(n^2 * 2^n) 巡回セールスマン問題　bitDP

/*
    2進数の数i,jが表す集合がS(i) ⊂ S(j) ならば i <= j
    となる性質から、配るDPのループを利用した更新順序でも問題なく更新ができます
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

int G[20][20];  // グラフ

/*
    dp[S][v]
    頂点0からスタートして、{0,1,2,…,n-1}の部分集合Sを巡回する|S|!通りの経路のうち最短のものの距離
    ただし、最後に頂点vに到達した時のみを考える
*/
int dp[50000][20];

int main() {
  int V, E;
  cin >> V >> E;

  // グラフの初期化
  rep(i, 20) rep(j, 20) G[i][j] = INF;

  rep(i, E) {
    int s, t, d;
    cin >> s >> t >> d;
    G[s][t] = d;
  }

  // dp の初期化
  rep(i, 50000) rep(j, 20) dp[i][j] = INF;
  dp[0][0] = 0;  // スタートを頂点 0 とする

  rep(S, 1 << V) {
    rep(v, V) {
      rep(u, V) {
        // 頂点vがSに所属していないことを確認
        if ((S & (1 << v)) == 0) {
          if (v != u) chmin(dp[S | (1 << v)][v], dp[S][u] + G[u][v]);
        }
      }
    }
  }

  if (dp[(1 << V) - 1][0] != INF) {
    cout << dp[(1 << V) - 1][0] << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}