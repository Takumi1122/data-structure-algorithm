#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  ll n, T;
  cin >> n >> T;
  vector<ll> t(n);
  rep(i, n) cin >> t[i];

  ll ans = 0;
  ll pre = 0;
  rep(i, n) {
    ans += min((T - (pre - t[i])), T);
    pre = t[i] + T;
  }

  cout << ans << endl;
  return 0;
}