#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 174 C - Repsept
      https://atcoder.jp/contests/abc174/tasks/abc174_c
*/

int main() {
  int k;
  cin >> k;

  int x = 7 % k;
  for (int i = 1; i <= k; ++i) {
    if (x == 0) {
      cout << i << endl;
      return 0;
    }
    x = (x * 10 + 7) % k;
  }

  cout << -1 << endl;
  return 0;
}
