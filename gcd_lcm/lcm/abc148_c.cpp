#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 最小公倍数 a / gcd(a, b) * b
// O(log(a)) a < b の場合

/*
    参考リンク
    ABC 148 C - Snack
      https://atcoder.jp/contests/abc148/tasks/abc148_c
*/

ll gcd(ll a, ll b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

int main() {
  ll a, b;
  cin >> a >> b;
  cout << a / gcd(a, b) * b << endl;
}