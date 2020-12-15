#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 累積GCD
// N個の値の中から1個だけ取り除いたN−1個の整数の最大公約数の最大値を求めよ

/*
    参考リンク
    ABC 125 C - GCD on Blackboard
      https://atcoder.jp/contests/abc125/tasks/abc125_c
*/

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

// O(log(a)) a < b の場合
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  // 累積gcd (左と右両方)
  // left[p]: 区間[0,p)の最大公約数
  // right[p]: 区間[p,N)の最大公約数
  vector<int> left(n + 1, 0), right(n + 1, 0);
  rep(i, n) left[i + 1] = gcd(left[i], a[i]);
  for (int i = n - 1; i >= 0; --i) right[i] = gcd(right[i + 1], a[i]);

  int ans = 0;
  rep(i, n) {
    int l = left[i];
    int r = right[i + 1];
    chmax(ans, gcd(l, r));
  }

  cout << ans << endl;
  return 0;
}