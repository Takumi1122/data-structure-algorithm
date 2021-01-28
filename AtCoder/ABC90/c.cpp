#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 偶奇性

/*
    参考リンク
    ABC 90 C - Flip,Flip, and Flip......
      https://atcoder.jp/contests/abc090/tasks/arc091_a
*/

int main() {
  ll n, m;
  cin >> n >> m;

  if (n == 1 && m == 1) {
    cout << 1 << endl;
    return 0;
  }

  if (n == 1 || m == 1) {
    // 両端のカードは2回,それ以外のカードは3回裏返される
    cout << n * m - 2 << endl;
  } else {
    // 四隅のカードは4回
    // それ以外の周上のカードは6回
    // それ以外のカードは9回
    cout << n * m - 2 * n - 2 * m + 4 << endl;
  }
  return 0;
}