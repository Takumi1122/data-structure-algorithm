#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 数列を(正,負,正,...)または(負,正,負,...)になるように変更する

/*
    参考リンク
    ABC 59 C - Sequence
      https://atcoder.jp/contests/abc059/tasks/arc072_a
*/

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  // pariが1なら奇数番目が正、0なら偶数番目が正
  auto check = [&](int pari) {
    ll cnt = 0;  // 必要な操作の回数
    ll sum = 0;  // i番目までの合計
    auto v = a;

    rep(i, n) {
      sum += v[i];
      if ((i + 1) % 2 == pari) {
        if (sum < 0) {
          cnt += abs(sum) + 1;
          sum += -sum + 1;
        } else if (sum == 0) {
          cnt++;
          sum = 1;
        }
      } else {
        if (sum > 0) {
          cnt += abs(sum) + 1;
          sum += -sum - 1;
        } else if (sum == 0) {
          cnt++;
          sum = -1;
        }
      }
    }
    return cnt;
  };

  ll ans = min(check(1), check(0));
  cout << ans << endl;
  return 0;
}