#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 浮動小数点数の整数判定

/*
    参考リンク
    ABC 133 B - Good Distance
      https://atcoder.jp/contests/abc133/tasks/abc133_b
*/

bool is_integer(double x) { return floor(x) == x; }

int main() {
  int n, d;
  cin >> n >> d;
  vector<vector<int>> x(n, vector<int>(d, 0));
  rep(i, n) rep(j, d) cin >> x[i][j];

  int ans = 0;
  rep(i, n) {
    for (int j = i + 1; j < n; j++) {
      int sum = 0;
      rep(k, d) sum += (x[j][k] - x[i][k]) * (x[j][k] - x[i][k]);
      double sq = sqrt(sum);
      if (is_integer(sq)) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}