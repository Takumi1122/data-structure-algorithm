#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 累積max

/*
    参考リンク
    ABC 182 B - Almost GCD
      https://atcoder.jp/contests/abc182/tasks/abc182_b
*/

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  ll cnt_max = 0;
  ll ans = 0;
  for (int i = 2; i <= 1000; i++) {
    ll cnt_s = 0;
    rep(j, n) {
      if (a[j] % i == 0) cnt_s++;
    }
    if (cnt_s > cnt_max) {
      ans = i;
      cnt_max = cnt_s;
    }
  }

  cout << ans << endl;
  return 0;
}