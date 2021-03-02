#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

/*
    参考リンク
    三井住友信託銀行プログラミングコンテスト2019 F - Interval Running
      https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_f
*/

int main() {
  ll t1, t2;
  ll a1, a2;
  ll b1, b2;
  cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
  a1 *= t1;
  a2 *= t2;
  b1 *= t1;
  b2 *= t2;
  a2 += a1;
  b2 += b1;

  // a1+a2 == b1+b2
  if (a2 == b2) {
    puts("infinity");
    return 0;
  }

  // a1+a2 < b1+b2 を a1+a2 > b1+b2として考える
  if (a2 < b2) {
    swap(a1, b1);
    swap(a2, b2);
  }

  ll d = a2 - b2;
  ll c = b1 - a1;
  ll ans = 0;
  // a1+a2 > b1+b2 && a1 > b1 ならば交差しない
  if (c > 0) {
    ans = (c + d - 1) / d;
    ans *= 2;
    ans--;
    if (c % d == 0) ans++;
  }

  cout << ans << endl;
  return 0;
}