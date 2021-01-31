#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 転倒数 O(nlogn)
// B の先頭の ai を削除すると転倒数は ai 減り,
// B の末尾に ai を追加すると転倒数は N−1−ai 増える

/*
    参考リンク
    ABC 190 F - Shift and Inversions
      https://atcoder.jp/contests/abc190/tasks/abc190_f
*/

template <typename T>
struct BIT {
  int n;
  vector<T> d;
  BIT(int n = 0) : n(n), d(n + 1) {}

  // i is 0-indexed
  // 0 <= i < n
  void add(int i, T x = 1) {
    for (i++; i <= n; i += i & -i) {
      d[i] += x;
    }
  }

  // [0, i], i is 0-indexed 閉区間
  // 0 <= i < n
  T sum(int i) {
    T x = 0;
    for (i++; i; i -= i & -i) {
      x += d[i];
    }
    return x;
  }

  // [l, r), l,r is 0-index 半開区間
  // 0 <= l <= r <= n
  T sum(int l, int r) { return sum(r - 1) - sum(l - 1); }
};

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  ll ans = 0;
  BIT<int> t(n);
  rep(i, n) {
    ans += t.sum(a[i], n);
    t.add(a[i], 1);
  }

  rep(k, n) {
    cout << ans << endl;
    ans -= a[k];
    ans += n - 1 - a[k];
  }
  return 0;
}