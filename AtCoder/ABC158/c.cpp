#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 最も小さい値を求める=>値が小さい方から全探索

/*
    参考リンク
    ABC158 C - Tax Increase
      https://atcoder.jp/contests/abc158/tasks/abc158_c
*/

int main() {
  int a, b;
  cin >> a >> b;

  for (int n = 0; n < 10000; ++n) {
    int za = n * 8 / 100;
    int zb = n * 10 / 100;
    if (a == za && b == zb) {
      cout << n << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}