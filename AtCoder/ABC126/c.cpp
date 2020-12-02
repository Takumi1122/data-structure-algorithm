#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 126 C - Dice and Coin
      https://atcoder.jp/contests/abc126/tasks/abc126_c
*/

int main() {
  int n, k;
  cin >> n >> k;

  double ans = 0.0;
  rep(i, n) {
    int p = (i + 1);
    double pb = 1.0 / n;
    while (p < k) {
      p *= 2;
      pb *= 0.5;
    }
    ans += pb;
  }

  printf("%.15f\n", ans);
  return 0;
}