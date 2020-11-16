#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 183 E - Queen on Grid
      https://atcoder.jp/contests/abc183/tasks/abc183_e
*/

const ll mod = 1000000007;
const int MAX = 2001;
ll a[MAX][MAX];
ll b[MAX][MAX];
ll c[MAX][MAX];
ll d[MAX][MAX];

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> f(h);
  rep(i, h) cin >> f[i];
  d[0][0] = 1;

  rep(i, h) rep(j, w) {
    if (f[i][j] == '#') continue;
    if (i == 0 && j == 0) continue;
    if (i - 1 >= 0 && f[i - 1][j] == '.') {
      a[i][j] = (a[i - 1][j] + d[i - 1][j]) % mod;
    }
    if (j - 1 >= 0 && f[i][j - 1] == '.') {
      b[i][j] = (b[i][j - 1] + d[i][j - 1]) % mod;
    }
    if (i - 1 >= 0 && j - 1 >= 0 && f[i - 1][j - 1] == '.') {
      c[i][j] = (c[i - 1][j - 1] + d[i - 1][j - 1]) % mod;
    }
    d[i][j] = (a[i][j] + b[i][j] + c[i][j]) % mod;
  }
  cout << d[h - 1][w - 1] << endl;
  return 0;
}