#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 異なる二点間のマンハッタン距離の最大の値

/*
    参考リンク
    ABC 178 E - Dist Max
      https://atcoder.jp/contests/abc178/tasks/abc178_e
*/

int main() {
  int n;
  cin >> n;
  vector<ll> x(n), y(n), sum(n), sub(n);
  rep(i, n) {
    cin >> x[i] >> y[i];
    sum[i] = x[i] + y[i];
    sub[i] = x[i] - y[i];
  }

  sort(sum.begin(), sum.end());
  sort(sub.begin(), sub.end());

  cout << max(sum.back() - sum[0], sub.back() - sub[0]) << endl;
  return 0;
}