#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 159 D - Banned K
      https://atcoder.jp/contests/abc159/tasks/abc159_d
*/

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  map<ll, ll> mp;
  rep(i, n) {
    cin >> a[i];
    mp[a[i]]++;
  }

  ll sum = 0;
  for (auto p : mp) {
    sum += p.second * (p.second - 1) / 2;
  }

  rep(i, n) {
    ll ans = sum - (mp[a[i]] * (mp[a[i]] - 1) / 2) +
             (mp[a[i]] - 2) * (mp[a[i]] - 1) / 2;
    cout << ans << endl;
  }
  return 0;
}