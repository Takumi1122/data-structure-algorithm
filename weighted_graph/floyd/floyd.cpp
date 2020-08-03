#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// o(|V|^3)

static const int MAX = 300;
static const ll INFTY = (1LL << 32);

int n;
ll d[MAX][MAX];

void floyd() {
  rep(k, n) {
    rep(i, n) {
      if (d[i][k] == INFTY) continue;
      rep(j, n) {
        if (d[k][j] == INFTY) continue;
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

int main() {
  int e, u, v, c;
  cin >> n >> e;

  rep(i, n) rep(j, n) d[i][j] = ((i == j) ? 0 : INFTY);

  rep(i, e) {
    cin >> u >> v >> c;
    d[u][v] = c;
  }

  floyd();

  bool negative = false;
  rep(i, n) if (d[i][i] < 0) negative = true;

  if (negative) {
    cout << "NEGATIVE CYCLE" << endl;
  } else {
    rep(i, n) {
      rep(j, n) {
        if (j) cout << " ";
        if (d[i][j] == INFTY)
          cout << "INF";
        else
          cout << d[i][j];
      }
      cout << endl;
    }
  }

  return 0;
}
