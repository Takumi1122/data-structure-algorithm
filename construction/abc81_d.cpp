#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 操作回数: 0~2N回
// 累積和と数列の大小関係

/*
    参考リンク
    ABC 81 D - Non-decreasing
      https://atcoder.jp/contests/abc081/tasks/arc086_b
*/

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  int mn = 1e9;
  int mx = -1e9;
  int mn_i, mx_i;
  rep(i, n) {
    if (a[i] > mx) {
      mx = a[i];
      mx_i = i + 1;
    }
    if (a[i] < mn) {
      mn = a[i];
      mn_i = i + 1;
    }
  }

  vector<P> ans;
  if (mn >= 0) {
    // aが非負整数のみからなる場合
    // aの先頭からの累積和を取った数列は条件を満たす
    rep(i, n - 1) ans.emplace_back(i + 1, i + 2);
  } else if (mx <= 0) {
    // aが0以下の整数のみからなる場合
    rep(i, n - 1) ans.emplace_back(n - i, n - i - 1);
  } else if (abs(mx) >= abs(mn)) {
    // aに負の数も正の数も含まれるとき
    // abs(mx) >= abs(mn)
    // すべての数にmxを足せばaを非負整数のみからなる数列にすることが可能
    rep(i, n) ans.emplace_back(mx_i, i + 1);
    rep(i, n - 1) ans.emplace_back(i + 1, i + 2);
  } else if (abs(mx) < abs(mn)) {
    // aに負の数も正の数も含まれるとき
    // abs(mx) < abs(mn)
    // すべての数にmnを足せばaを0以下の整数のみからなる数列にすることが可能
    rep(i, n) ans.emplace_back(mn_i, i + 1);
    rep(i, n - 1) ans.emplace_back(n - i, n - i - 1);
  }

  cout << ans.size() << endl;
  rep(i, ans.size()) cout << ans[i].first << " " << ans[i].second << endl;
  return 0;
}