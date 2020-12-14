#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 連続するn個の自然数の積は、かならずn!で割り切れる
// オーバーフローに注意 c(l-1,11)

/*
    参考リンク
    ABC 185 C - Duodecim Ferra
      https://atcoder.jp/contests/abc185/tasks/abc185_c
*/

int main() {
  int l;
  cin >> l;

  __int128 ans = 1;
  int div = 1;
  for (int i = 1; i <= 11; ++i) {
    ans *= l - i;
    div *= i;
  }
  ans /= div;
  cout << (ll)(ans) << endl;
  return 0;
}