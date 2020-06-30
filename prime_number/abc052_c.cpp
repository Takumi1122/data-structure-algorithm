#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// n!の約数個数　o(n * √n)

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

  const int MOD = 1000000007;
  vector<ll> ex(n + 1, 0);  // exp[p] := p の指数
  for (ll i = 2; i <= n; ++i) {
    const auto &res = prime_factorize(i);  // n の素因数分解
    for (auto p : res) ex[p.first] += p.second;
  }
  ll res = 1;
  for (int p = 2; p <= n; ++p) {
    res *= ex[p] + 1;  // 約数の個数は (exp + 1) の積
    res %= MOD;
  }
  cout << res << endl;
}