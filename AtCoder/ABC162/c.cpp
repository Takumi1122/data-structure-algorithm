#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 162 C - Sum of gcd of Tuples (Easy)
      https://atcoder.jp/contests/abc162/tasks/abc162_c
*/

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
  int k;
  cin >> k;

  ll ans = 0;
  for (int a = 1; a <= k; ++a) {
    for (int b = 1; b <= k; ++b) {
      for (int c = 1; c <= k; ++c) {
        ans += gcd(gcd(a, b), c);
      }
    }
  }

  cout << ans << endl;
  return 0;
}