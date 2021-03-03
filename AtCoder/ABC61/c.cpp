#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  ll n, k;
  cin >> n >> k;
  map<ll, ll> mp;
  rep(i, n) {
    ll a, b;
    cin >> a >> b;
    mp[a] += b;
  }

  ll ans = 0;
  for (auto p : mp) {
    if (p.second >= k) {
      ans = p.first;
      break;
    } else {
      k -= p.second;
    }
  }
  cout << ans << endl;
  return 0;
}