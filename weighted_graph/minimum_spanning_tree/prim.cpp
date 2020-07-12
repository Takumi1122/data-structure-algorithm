#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

static const int MAX = 100;
static const int INFTY = (1 << 21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

// o(|v|^2)
// 最小全域木: グラフの全域木のなかで、辺の重みの総和が最小のもの
// 木は閉路がない
// 全域木は頂点を全て含む木

// n: 頂点数
// M: 隣接行列
int n, M[MAX][MAX];

int prim() {
  int u, minv;

  // p[v] 頂点vの親
  int d[MAX], p[MAX], color[MAX];

  rep(i, n) {
    d[i] = INFTY;
    p[i] = -1;
    color[i] = WHITE;
  }

  d[0] = 0;

  while (1) {
    minv = INFTY;
    u = -1;
    rep(i, n) {
      if (minv > d[i] && color[i] != BLACK) {
        u = i;
        minv = d[i];
      }
    }
    if (u == -1) break;
    color[u] = BLACK;
    rep(v, n) {
      if (color[v] != BLACK && M[u][v] != INFTY) {
        if (d[v] > M[u][v]) {
          d[v] = M[u][v];
          p[v] = u;
          color[v] = GRAY;
        }
      }
    }
  }
  int sum = 0;
  rep(i, n) {
    if (p[i] != -1) sum += M[i][p[i]];
  }

  return sum;
}

int main() {
  cin >> n;

  rep(i, n) {
    rep(j, n) {
      int e;
      cin >> e;
      M[i][j] = (e == -1) ? INFTY : e;
    }
  }

  cout << prim() << endl;

  return 0;
}