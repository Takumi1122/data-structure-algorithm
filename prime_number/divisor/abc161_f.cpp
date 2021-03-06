#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 161 F - Division or Subtraction
      https://atcoder.jp/contests/abc161/tasks/abc161_f
*/

vector<ll> enumDivisor(ll n) {
  vector<ll> res;
  for (ll i = 1; i * i <= n; ++i) {
    if (n % i != 0) continue;
    res.push_back(i);
    if (i * i != n) res.push_back(n / i);
  }
  return res;
}

int main() {
  ll n;
  cin >> n;
  int ans = 0;
  for (ll x : enumDivisor(n)) {
    if (x == 1) continue;
    ll tmp = n;
    while (tmp % x == 0) tmp /= x;
    tmp %= x;
    if (tmp == 1) ++ans;
  }
  // -1は約数1を除外している
  ans += enumDivisor(n - 1).size() - 1;
  cout << ans << endl;
  return 0;
}