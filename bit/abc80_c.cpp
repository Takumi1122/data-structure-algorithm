#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

/*
    参考リンク
    ABC 80 C - Shopping Street
      https://atcoder.jp/contests/abc080/tasks/abc080_c
*/

int main() {
  int n;
  cin >> n;
  vector<vector<int>> f(n, vector<int>(10));
  vector<vector<int>> p(n, vector<int>(11));
  rep(i, n) rep(j, 10) cin >> f[i][j];
  rep(i, n) rep(j, 11) cin >> p[i][j];

  int ans = -1e9 - 10;
  rep(bit, 1 << 10) {
    if (__builtin_popcountll(bit) == 0) continue;
    int sum = 0;
    rep(i, n) {
      int cnt = 0;
      rep(j, 10) {
        if (bit & (1 << j) && f[i][j]) cnt++;
      }
      sum += p[i][cnt];
    }
    ans = max(ans, sum);
  }

  cout << ans << endl;
  return 0;
}