#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 互いに素 = 2つの整数が、ともに同じ2以上の整数で割り切れることは無い

/*
    参考リンク
    ARC 114 A - Not coprime
      https://atcoder.jp/contests/arc114/tasks/arc114_a
*/

// O(log(a)) a < b の場合
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
  ll n;
  cin >> n;
  vector<ll> x(n);
  rep(i, n) cin >> x[i];

  vector<ll> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
  ll ans = 1e18;

  rep(bit, 1 << p.size()) {
    bool ok = true;
    ll sum = 1;
    rep(i, p.size()) {
      if (bit & (1 << i)) sum *= p[i];
    }
    for (auto xi : x) {
      if (gcd(xi, sum) == 1) {
        ok = false;
      }
    }
    if (ok) ans = min(ans, sum);
  }

  cout << ans << endl;
  return 0;
}