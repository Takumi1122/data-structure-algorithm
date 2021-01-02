#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 桁和

ll digsum(ll n) {
  ll res = 0;
  while (n > 0) {
    res += n % 10;
    n /= 10;
  }
  return res;
}