#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 解を仮定し可能かを二分探索で判定
// 最小値を求める
// 最大値の最小化

/*
    参考リンク
    ABC 174 E - Logs
      https://atcoder.jp/contests/abc174/tasks/abc174_e
*/

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  // 解を決め打ち
  int l = 0, r = 1e9;
  while (r - l > 1) {
    int x = (l + r) / 2;
    // x <= x' について f(x) = true なら f(x') = true
    auto f = [&](int x) {
      ll now = 0;
      rep(i, n) now += (a[i] - 1) / x;
      return now <= k;
    };

    if (f(x))
      r = x;
    else
      l = x;
  }

  cout << r << endl;
  return 0;
}
