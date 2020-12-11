#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 約数の個数 O(√n)

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
  ll n;
  cin >> n;
  const auto &pf = prime_factorize(n);
  ll res = 1;
  for (auto p : pf) res *= p.second + 1;
  cout << res << endl;
}