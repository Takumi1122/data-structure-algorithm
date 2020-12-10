#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// i<j
// j-i = a[i]+a[j]
// a[i]+i = j-a[j]

/*
    参考リンク
    ABC 166 E - This Message Will Self-Destruct in 5s
      https://atcoder.jp/contests/abc166/tasks/abc166_e
*/

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  map<int, int> mp;
  ll ans = 0;
  rep(i, n) {
    int sa = i - a[i];
    ans += mp[sa];
    int wa = a[i] + i;
    mp[wa]++;
  }

  cout << ans << endl;
  return 0;
}
