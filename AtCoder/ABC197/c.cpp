#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll ans = 1e18;
  ll x = 0;
  rep(i, n) x |= a[i];
  ans = min(ans, x);

  rep(bit, 1 << (n - 1)) {
    if (__builtin_popcount(bit) == 0) continue;
    vector<vector<ll>> b(__builtin_popcount(bit) + 1);
    int pre = 0;
    int id = 0;
    rep(i, n - 1) {
      if (bit & (1 << i)) {
        vector<ll> c;
        for (int j = pre; j <= i; j++) {
          b[id].push_back(a[j]);
        }
        pre = i + 1;
        id++;
      }
    }
    for (int j = pre; j < n; j++) {
      b[id].push_back(a[j]);
    }

    ll sum = 0;
    rep(i, b.size()) {
      ll x = 0;
      rep(j, b[i].size()) x |= b[i][j];
      sum ^= x;
    }
    ans = min(ans, sum);
  }

  cout << ans << endl;
  return 0;
}