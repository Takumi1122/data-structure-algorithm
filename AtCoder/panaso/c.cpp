#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// ルートの不等式を変形
// a,bが正の時: a < b <=> a^2 < b^2

/*
    参考リンク
    パナソニックプログラミングコンテスト2020 C - Sqrt Inequality
      https://atcoder.jp/contests/panasonic2020/tasks/panasonic2020_c
*/

int main() {
  ll a, b, c;
  cin >> a >> b >> c;

  ll l, r;
  l = 4 * a * b;
  r = (c - (a + b)) * (c - (a + b));

  if (l < r && c - (a + b) > 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}