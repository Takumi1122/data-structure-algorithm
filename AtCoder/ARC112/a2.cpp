#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// A−B=C を満たすL以上R以下の整数A,B,Cの組がいくつあるか

/*
    参考リンク
    ARC 112 A - B = C
      https://atcoder.jp/contests/arc112/tasks/arc112_a
*/

// a + (a+1) + ... + b
ll sum(ll a, ll b) { return (a + b) * (b - a + 1) / 2; }

int main() {
  int t;
  cin >> t;

  while (t--) {
    ll l, r;
    cin >> l >> r;
    ll min_c = l;
    ll max_c = r - l;
    if (min_c > max_c) {
      cout << 0 << endl;
    } else {
      cout << sum(r - max_c - l + 1, r - min_c - l + 1) << endl;
    }
  }
  return 0;
}