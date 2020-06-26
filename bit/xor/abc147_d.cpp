#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MOD = 1000000007;
int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll res = 0;
  ll two_factor = 1;
  for (int d = 0; d < 60; ++d) {
    ll even = 0, odd = 0;
    rep(i, n) {
      if (a[i] & (1LL << d))
        ++odd;
      else
        ++even;
    }
    ll add = (odd * even) % MOD * two_factor % MOD;
    res = (res + add) % MOD;
    two_factor = (two_factor * 2) % MOD;
  }
  cout << res << endl;
}