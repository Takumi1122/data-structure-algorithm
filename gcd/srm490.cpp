#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

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