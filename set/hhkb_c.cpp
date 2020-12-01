#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// Mex: 最小除外数(Minimum excludant)
// 集合に含まれない最も小さい非負整数を返す関数

/*
    参考リンク
    HHKB C - Neq Min
      https://atcoder.jp/contests/hhkb2020/tasks/hhkb2020_c
*/

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  rep(i, n) cin >> p[i];

  int ans = 0;
  set<int> s;
  rep(i, n) {
    int pi = p[i];
    s.insert(pi);
    while (s.count(ans)) ans++;
    cout << ans << endl;
  }
  return 0;
}