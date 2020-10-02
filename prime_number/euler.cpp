#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// オイラー関数値 O(√n)
// 正の整数Nが与えられたとき、1,2,…,Nのうち
// Nと互いに素であるものの個数をφ(N)と表します。これをオイラー関数とよびます。
// φ(N) = N((p1 - 1) / p1)((p2 - 1) / p2)...((pk - 1) / pk)

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
  ll res = n;
  for (auto p : pf) {
    res *= (p.first - 1);
    res /= p.first;
  }
  cout << res << endl;
}