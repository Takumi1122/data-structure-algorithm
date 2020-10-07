#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    正の整数Nに対して単調増加な式f(N)があるとき、

    ・f(N) ≤ X を満たす最大の正の整数N

    は、二分探索によって求めることができる
*/

/*
    参考リンク
    ABC 146 C - Buy an Integer
      https://atcoder.jp/contests/abc146/tasks/abc146_c
*/

int main() {
  ll a, b, x;
  cin >> a >> b >> x;

  // 二分探索用の関数
  auto keta = [&](ll n) {
    ll res = 0;
    while (n) ++res, n /= 10;
    return res;
  };

  auto f = [&](ll n) { return a * n + b * keta(n); };

  ll l = 0, r = 1e9 + 1;
  while (l + 1 < r) {
    ll mid = (l + r) / 2;
    if (x >= f(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }

  cout << l << endl;
  return 0;
}