#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 連続する部分列で、その積がK以下となるもののうち、最大の長さ

/*
    参考リンク
    ABC 032 C - 列
      https://atcoder.jp/contests/abc032/tasks/abc032_c
*/

int main() {
  int n;
  ll k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  rep(i, n) {
    if (a[i] == 0) {
      cout << n << endl;
      return 0;
    }
  }

  int res = 0;
  int right = 0;
  ll mul = 1;
  rep(left, n) {
    while (right < n && mul * a[right] <= k) {
      mul *= a[right];
      ++right;
    }
    res = max(res, right - left);
    if (left == right)
      ++right;
    else
      mul /= a[left];
  }

  cout << res << endl;
  return 0;
}