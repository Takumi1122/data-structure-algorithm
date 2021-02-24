#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// next_permutation
// 要素の数は2以上
// 要素は整数(本来は < 演算子が使えればなんでもいい)
// 予めソート済み

/*
    参考リンク
    ABC 73 D - joisino's travel
      https://atcoder.jp/contests/abc073/tasks/abc073_d
*/

const int INF = 1001001001;

int main() {
  int n, m, r;
  cin >> n >> m >> r;
  vector<vector<int>> d(n, vector<int>(n, INF));
  rep(i, n) rep(j, n) if (i == j) d[i][j] = 0;
  vector<int> r1(r);
  rep(i, r) {
    int ri;
    cin >> ri;
    ri--;
    r1[i] = ri;
  }
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    d[a][b] = c;
    d[b][a] = c;
  }

  rep(k, n) rep(i, n) rep(j, n) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

  sort(r1.begin(), r1.end());
  int ans = INF;
  do {
    int sum = 0;
    rep(i, r - 1) sum += d[r1[i]][r1[i + 1]];
    ans = min(ans, sum);
  } while (next_permutation(r1.begin(), r1.end()));

  cout << ans << endl;
  return 0;
}