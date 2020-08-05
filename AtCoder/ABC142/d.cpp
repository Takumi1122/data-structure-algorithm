#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

set<ll> prime_factorize(ll n) {
  set<ll> res;
  for (ll a = 2; a * a <= n; ++a) {
    if (n % a != 0) continue;
    ll ex = 0;  // 指数

    // 割れる限り割り続ける
    while (n % a == 0) {
      ++ex;
      n /= a;
    }

    // その結果を push
    res.insert(a);
  }

  // 最後に残った数について
  if (n != 1) res.insert(n);
  return res;
}

int main() {
  ll a, b;
  cin >> a >> b;
  set<ll> as = prime_factorize(a);
  set<ll> bs = prime_factorize(b);
  set<ll> ans;
  for (auto &s : as) {
    if (bs.count(s)) {
      ans.insert(s);
    }
  }

  cout << ans.size() + 1 << endl;
  return 0;
}