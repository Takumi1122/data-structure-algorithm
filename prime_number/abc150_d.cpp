#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// o(n * log(n))

ll gcd(ll x, ll y) {
  if (y == 0)
    return x;
  else
    return gcd(y, x % y);
}

ll solve(int n, ll m, vector<ll> &a) {
  // 2 で割れるだけ割る (割れる回数が異なったらダメ)
  bool same = true;
  while (a[0] % 2 == 0) {
    rep(i, n) {
      if (a[i] % 2 != 0) return 0;
      a[i] /= 2;
    }
    m /= 2;
  }
  rep(i, n) if (a[i] % 2 == 0) return 0;

  // lcm
  ll lcm = 1;
  rep(i, n) {
    ll g = gcd(lcm, a[i]);
    lcm = lcm / g * a[i];
    if (lcm > m) return 0;
  }
  return (m / lcm + 1) / 2;
}

int main() {
  int n;
  ll m;
  cin >> n >> m;
  vector<ll> a(n);

  // あらかじめ a は一回 2 で割っておく
  rep(i, n) cin >> a[i], a[i] /= 2;
  cout << solve(n, m, a) << endl;
}