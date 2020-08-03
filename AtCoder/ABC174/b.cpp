#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, d;
  cin >> n >> d;
  vector<pair<ll, ll> > p(n);
  ll ans = 0;
  rep(i, n) cin >> p[i].first >> p[i].second;
  rep(i, n) {
    ll dist = p[i].first * p[i].first + p[i].second * p[i].second;
    if (d * d >= dist) ans++;
  }
  cout << ans << endl;
  return 0;
}