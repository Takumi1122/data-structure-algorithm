#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// N * M = P についてPの約数から

/*
    参考リンク
    ARC 108 A - Sum and Product
      https://atcoder.jp/contests/arc108/tasks/arc108_a
*/

vector<ll> enum_divisors(ll n) {
  vector<ll> res;
  for (ll i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      res.push_back(i);
      if (n / i != i) res.push_back(n / i);
    }
  }
  sort(res.begin(), res.end());
  return res;
}

int main() {
  ll s, p;
  cin >> s >> p;
  auto a = enum_divisors(p);
  for (auto n : a) {
    ll m = p / n;
    if (n + m == s) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}