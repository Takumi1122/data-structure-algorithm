#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    // 倍数の周期性
    整数a,mが互いに素であるとする
    0,a,2a,…,(m−1)a をmで割ったあまりを並び替えると、
    0,1,2,…,m-1 に一致する
*/

ll gcd(ll a, ll b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

class Starport {
 public:
  double getExpectedTime(ll n, ll m) {
    ll g = gcd(n, m);
    n /= g;
    m /= g;
    return (double)(n - 1) * g / 2;
  }
};