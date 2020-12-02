#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 127 D - Integer Cards
      https://atcoder.jp/contests/abc127/tasks/abc127_d
*/

int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  vector<pair<ll, ll>> bc(m);
  rep(i, m) cin >> bc[i].second >> bc[i].first;
  sort(bc.begin(), bc.end(), greater<pair<ll, ll>>());

  priority_queue<ll, vector<ll>, greater<ll>> pq;
  rep(i, n) pq.push(a[i]);
  rep(i, m) {
    rep(j, bc[i].second) {
      ll t = pq.top();
      if (t < bc[i].first) {
        pq.pop();
        pq.push(bc[i].first);
      } else {
        break;
      }
    }
  }

  ll ans = 0;
  rep(i, n) {
    ans += pq.top();
    pq.pop();
  }
  cout << ans << endl;
  return 0;
}