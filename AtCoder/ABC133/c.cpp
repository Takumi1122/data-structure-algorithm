#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 2019 個以上の整数が連続すると、その中に必ず 2019 の倍数がある

/*
    参考リンク
    ABC 133 C - Remainder Minimization 2019
      https://atcoder.jp/contests/abc133/tasks/abc133_c
*/

int main() {
  int l, r;
  cin >> l >> r;
  if (r - l + 1 >= 2019) {
    cout << 0 << endl;
    return 0;
  }

  int ans = 2020;
  for (int i = l; i <= r; i++) {
    for (int j = i + 1; j <= r; j++) {
      int md = (i % 2019) * (j % 2019) % 2019;
      ans = min(ans, md);
    }
  }
  cout << ans << endl;
  return 0;
}