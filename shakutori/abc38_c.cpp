#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 連続する部分列のうち、単調増加となっているものを数え上げ

/*
    参考リンク
    ABC 038 C - 単調増加
      https://atcoder.jp/contests/abc038/tasks/abc038_c
*/

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll res = 0;
  int right = 1;
  rep(left, n) {
    while (right < n && (right <= left || a[right - 1] < a[right])) {
      ++right;
    }
    res += right - left;
    if (left == right) ++right;
  }

  cout << res << endl;
}