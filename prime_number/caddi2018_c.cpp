#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 素数をなるべく均等に分配 O(√p)

/*
    参考リンク
    CADDi 2018 C - Product and GCD
      https://atcoder.jp/contests/caddi2018/tasks/caddi2018_a
*/

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
  int n;
  ll p;
  cin >> n >> p;
  const auto &pf = prime_factorize(p);
  ll res = 1;
  for (auto p : pf) {
    for (int j = 0; j < p.second / n; ++j) res *= p.first;
  }
  cout << res << endl;
}