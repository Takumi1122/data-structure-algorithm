#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

/*
    参考リンク
    ARC 112 B - -- - B
      https://atcoder.jp/contests/arc112/tasks/arc112_b
*/

int main() {
  ll b, c;
  cin >> b >> c;
  ll mx1 = b + ((c - 2) / 2);
  ll mn1 = b - (c / 2);
  ll mx2 = -b + ((c - 1) / 2);
  ll mn2 = -b - ((c - 1) / 2);

  // 重なっている区間を引くのを忘れない
  ll ans = (mx1 - mn1 + 1) + (mx2 - mn2 + 1) -
           max(min(mx1, mx2) - max(mn1, mn2) + 1, 0LL);
  cout << ans << endl;
  return 0;
}