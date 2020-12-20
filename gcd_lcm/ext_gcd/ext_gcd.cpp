#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// O(log(a)) a < b の場合
// ax + by = gcd(a, b) となるような (x, y) を求める
// 多くの場合 a と b は互いに素として ax + by = 1 となる (x, y) を求める
// d = gcd(a, b)を戻り値として返す関数
ll extGCD(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  // 再帰的に解く (x, y を入れ替えておく)
  ll d = extGCD(b, a % b, y, x);
  y -= a / b * x;
  return d;
}