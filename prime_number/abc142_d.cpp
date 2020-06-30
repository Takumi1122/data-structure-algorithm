#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 最大公約数を求める
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }

// 素因数分解
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
  ll a, b;
  cin >> a >> b;

  // 最大公約数を求める
  ll g = gcd(a, b);

  // G を素因数分解して、「素因数の個数 + 1」が答え
  const auto &pf = prime_factorize(g);
  cout << pf.size() + 1 << endl;
}