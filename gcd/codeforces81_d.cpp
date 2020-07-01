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

vector<pair<ll, ll> > prime_factorize(ll n) {
  vector<pair<ll, ll> > res;
  for (ll a = 2; a * a <= n; ++a) {
    if (n % a != 0) continue;
    ll ex = 0;
    while (n % a == 0) {
      ++ex;
      n /= a;
    }
    res.push_back({a, ex});
  }
  if (n != 1) res.push_back({n, 1});
  return res;
}

int main() {
  int t;
  cin >> t;
  rep(i, t) {
    ll a, m;
    cin >> a >> m;
    ll g = gcd(a, m);
    m /= g;
    const auto &pf = prime_factorize(m);
    ll res = m;
    for (auto p : pf) res = res / p.first * (p.first - 1);
    cout << res << endl;
  }