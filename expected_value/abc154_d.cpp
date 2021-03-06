#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 期待値 1*(1/p)+2*(1/p)+...+p*(1/p) = (p + 1)/2

/*
    参考リンク
    ABC 154 D - Dice in Line
      https://atcoder.jp/contests/abc154/tasks/abc154_d
*/

int main() {
  int n, k;
  cin >> n >> k;
  vector<double> p(n);
  rep(i, n) {
    cin >> p[i];
    p[i] = (p[i] + 1) / 2;
  }

  vector<double> sum(n + 1);
  rep(i, n) sum[i + 1] = sum[i] + p[i];

  double ans = 0;
  for (int i = 0; i <= n - k; ++i) {
    double ev = sum[k + i] - sum[i];
    ans = max(ans, ev);
  }

  printf("%.15f\n", ans);
  return 0;
}