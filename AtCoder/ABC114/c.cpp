#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 1以上n以下の整数のうち
// 数字7,5,3がそれぞれ1回以上現れ

/*
    参考リンク
    ABC 114 C - 755
      https://atcoder.jp/contests/abc114/tasks/abc114_c
*/

ll n;
// now: 現在の値, use:7,5,3のうちどれを使ったか, cnt: 答え
void rec(ll now, int use, ll &cnt) {
  if (now > n) return;
  if (use == 0b111) ++cnt;

  rec(now * 10 + 7, use | 0b001, cnt);
  rec(now * 10 + 5, use | 0b010, cnt);
  rec(now * 10 + 3, use | 0b100, cnt);
}

int main() {
  cin >> n;

  ll ans = 0;
  rec(0, 0, ans);

  cout << ans << endl;
  return 0;
}