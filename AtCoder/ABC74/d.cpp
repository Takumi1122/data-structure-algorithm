#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

/*
    参考リンク
    ABC 74 D - Restoring Road Network
      https://atcoder.jp/contests/abc074/tasks/arc083_b
*/

int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  vector<vector<bool>> b(n, vector<bool>(n));
  rep(i, n) rep(j, n) cin >> a[i][j];

  rep(k, n) rep(i, n) rep(j, n) {
    if (k == j || k == i) continue;

    // a[i][j]は最短経路ではなくなる
    if (a[i][j] > a[i][k] + a[k][j]) {
      cout << "-1" << endl;
      return 0;
    }

    // a[i][j]の辺は消せる
    if (a[i][j] == a[i][k] + a[k][j]) {
      b[i][j] = true;
    }
  }

  ll ans = 0;
  // 辺を重複しないようにする
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (b[i][j] == false) ans += a[i][j];
    }
  }

  cout << ans << endl;
  return 0;
}