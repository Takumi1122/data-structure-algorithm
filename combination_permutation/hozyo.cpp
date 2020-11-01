#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 包除原理 集合の個数が少ない時に使える O(2^m * f)
// 蟻本P264: 包除原理

// O(log(a)) a < b の場合
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(m);
  rep(i, m) cin >> a[i];

  ll ans = 0;
  for (int i = 1; i < (1 << m); i++) {
    int num = 0;
    // iの立っているビット数
    for (int j = i; j != 0; j >>= 1) num += j & 1;
    ll lc = 1;
    for (int j = 0; j < m; j++) {
      if (i >> j & 1) {
        lc = lcm(lc, a[j]);
        if (lc > n) break;
      }
    }
    if (num % 2 == 0)
      ans -= n / lc;
    else
      ans += n / lc;
  }
  cout << ans << endl;
  return 0;
}