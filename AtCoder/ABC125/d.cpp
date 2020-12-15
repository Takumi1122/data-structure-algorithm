#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// マイナスの位置をswapできる
// マイナスの数の偶奇は変わらない: 不変量

/*
    参考リンク
    ABC 125 D - Flipping Signs
      https://atcoder.jp/contests/abc125/tasks/abc125_d
*/

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  int num_minus = 0;
  ll mi = 1LL << 60;
  ll sum = 0;
  rep(i, n) {
    if (a[i] < 0) ++num_minus;
    chmin(mi, abs(a[i]));
    sum += abs(a[i]);
  }

  if (num_minus % 2 == 0)
    cout << sum << endl;
  else
    cout << sum - mi * 2 << endl;
  return 0;
}