#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

#include <atcoder/all>
using namespace atcoder;

// グリッドグラフをますの偶奇で二部グラフと考える
// 蟻本P357

const int di[] = {0, 1, 0, -1};
const int dj[] = {-1, 0, 1, 0};
const int INF = 1e9;

int main() {
  int T;
  cin >> T;

  rep(ti, T) {
    int n, m;
    cin >> n >> m;
    // 白:'.' 青:'#'
    vector<string> st(n);
    rep(i, n) cin >> st[i];

    int s = n * m;
    int t = s + 1;

    int df = 0;
    mf_graph<int> g(n * m + 2);

    rep(i, n) {
      rep(j, m) {
        int now = i * m + j;
        if ((i + j) % 2 == 0) {
          if (st[i][j] == '?') {
            df += 4;
            // 青にする
            g.add_edge(s, now, 0);
            // 白にする
            g.add_edge(now, t, 4);
            rep(d, 4) {
              int ni = i + di[d];
              int nj = j + dj[d];
              int nx = ni * m + nj;
              if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
              if (st[ni][nj] == '#' || st[ni][nj] == '?')
                // odd -> even への辺をはる
                g.add_edge(nx, now, 2);
            }
          } else if (st[i][j] == '#') {
            df += 4;
            // 青を青にできないようにINF
            g.add_edge(now, t, INF);
            rep(d, 4) {
              int ni = i + di[d];
              int nj = j + dj[d];
              if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
              // 青が隣接していると幸福度が2下がる
              if (st[ni][nj] == '#') df -= 2;
            }
          }
        } else {
          if (st[i][j] == '?') {
            df += 4;
            // 白にする
            g.add_edge(s, now, 4);
            // 青にする
            g.add_edge(now, t, 0);
            rep(d, 4) {
              int ni = i + di[d];
              int nj = j + dj[d];
              int nx = ni * m + nj;
              if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
              if (st[ni][nj] == '#') g.add_edge(now, nx, 2);
            }
          } else if (st[i][j] == '#') {
            df += 4;
            // 青を青にできないようにINF
            g.add_edge(s, now, INF);
          }
        }
      }
    }

    cout << df - g.flow(s, t) << endl;
  }

  return 0;
}
