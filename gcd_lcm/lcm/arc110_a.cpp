#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 1~Nの最小公倍数 + 1

/*
    参考リンク
    ARC 110 A - Redundant Redundancy
      https://atcoder.jp/contests/arc110/tasks/arc110_a
*/

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
  int n;
  cin >> n;
  ll lc = 1;
  for (int i = 2; i <= n; i++) {
    lc = lcm(lc, i);
  }
  cout << lc + 1 << endl;
  return 0;
}