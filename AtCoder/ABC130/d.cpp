#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 130 D - Enough Array
      https://atcoder.jp/contests/abc130/tasks/abc130_d
*/

int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll res = 0;
  int right = 0;
  ll sum = 0;
  for (int left = 0; left < n; ++left) {
    while (right < n && sum + a[right] < k) {
      sum += a[right];
      ++right;
    }
    res += (right - left);
    if (right == left)
      ++right;
    else
      sum -= a[left];
  }

  ll ans = n * (n + 1) / 2 - res;
  cout << ans << endl;
  return 0;
}