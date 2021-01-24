#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 浮動小数点 整数で計算する

/*
    参考リンク
    ABC 189 B - Alcoholic
      https://atcoder.jp/contests/abc189/tasks/abc189_b
*/

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> v(n), p(n);
  rep(i, n) cin >> v[i] >> p[i];

  int sum = 0;
  rep(i, n) {
    sum += v[i] * p[i];
    if (100 * x < sum) {
      cout << i + 1 << endl;
      return 0;
    }
  }

  cout << -1 << endl;
  return 0;
}