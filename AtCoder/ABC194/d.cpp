#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 確率pで成功する試行を、成功するまで行うときの試行回数の期待値は1/pである

/*
    参考リンク
    ABC 194 D - Journey
      https://atcoder.jp/contests/abc194/tasks/abc194_d
*/

int main() {
  int n;
  cin >> n;

  double ans = 0.0;
  for (int i = 1; i < n; i++) {
    double x = (double)(n - i) / n;
    ans += 1.0 / x;
  }

  printf("%.15f\n", ans);
  return 0;
}