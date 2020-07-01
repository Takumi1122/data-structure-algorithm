#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// o(n * log(n)) 最大公約数はo(log(n))

ll gcd(ll a, ll b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

int main() {
  int n;
  cin >> n;
  ll x;
  cin >> x;
  ll res = 0;
  rep(i, n) {
    ll xi;
    cin >> xi;
    res = gcd(res, abs(xi - x));
  }
  cout << res << endl;
}