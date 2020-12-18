#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<pll> ab(n);
  rep(i, n) cin >> ab[i].first >> ab[i].second;
  sort(ab.begin(), ab.end());

  ll ans = 0;
  rep(i, n) {
    if (m - ab[i].second >= 0) {
      m -= ab[i].second;
      ans += ab[i].first * ab[i].second;
    } else {
      ans += ab[i].first * m;
      break;
    }
  }

  cout << ans << endl;
  return 0;
}