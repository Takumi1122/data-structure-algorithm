#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 自己交叉のない多角形
// マス目

/*
    参考リンク
    ABC 191 C - Digital Graffiti
      https://atcoder.jp/contests/abc191/tasks/abc191_c
*/

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> f(h);
  rep(i, h) cin >> f[i];

  int ans = 0;
  rep(i, h - 1) rep(j, w - 1) {
    int cnt = 0;
    rep(di, 2) rep(dj, 2) if (f[i + di][j + dj] == '#') cnt++;
    if (cnt == 1 || cnt == 3) ++ans;
  }

  cout << ans << endl;
  return 0;
}