#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 193 F - Zebraness
      https://atcoder.jp/contests/abc193/tasks/abc193_f
*/

int di[] = {-1, 0, 1, 0};
int dj[] = {0, -1, 0, 1};

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) cin >> s[i];

  int sv = n * n, tv = sv + 1;
  mf_graph<int> g(tv + 1);
  const int M = 5;
  int tot = 0;

  rep(i, n) rep(j, n) {
    int a = i * n + j;
    rep(v, 4) {
      int ni = i + di[v], nj = j + dj[v];
      if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
      int b = ni * n + nj;
      g.add_edge(a, b, 1);
      if (a < b) tot += 1;
    }
    if (s[i][j] == '?') {
      // ?の場合はsvとtvの両方に辺を貼る
      g.add_edge(sv, a, M);
      g.add_edge(a, tv, M);
      tot += M;
    } else {
      // 奇数番目のグリッドについてBとWを反転
      // BとWの場合、svもしくはtvのどちらかに辺を貼る
      if ((s[i][j] == 'B') && ((i + j) % 2 == 0)) {
        g.add_edge(sv, a, M);
      } else if ((s[i][j] == 'W') && ((i + j) % 2 == 0)) {
        g.add_edge(a, tv, M);
      }
      if ((s[i][j] == 'B') && ((i + j) % 2 == 1)) {
        g.add_edge(a, tv, M);
      } else if ((s[i][j] == 'W') && ((i + j) % 2 == 1)) {
        g.add_edge(sv, a, M);
      }
    }
  }

  int ans = tot - g.flow(sv, tv);
  cout << ans << endl;
  return 0;
}