#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// i<j
// j-i = a[i]+a[j]
// a[i]+i = j-a[j]

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  map<int, int> mp;
  ll ans = 0;
  rep(i, n) {
    int sa = i - a[i];
    int wa = a[i] + i;
    ans += mp[sa];
    mp[wa]++;
  }
  cout << ans << endl;
  return 0;
}
