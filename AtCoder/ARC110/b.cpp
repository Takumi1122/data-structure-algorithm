#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 部分文字列

/*
    参考リンク
    ARC 110 B - Many 110
      https://atcoder.jp/contests/arc110/tasks/arc110_b
*/

int main() {
  ll n;
  string t;
  cin >> n >> t;

  if (t == "1") {
    ll sum = 2e10;
    cout << sum << endl;
    return 0;
  }
  if (t == "11") {
    ll sum = 1e10;
    cout << sum << endl;
    return 0;
  }

  string s = "";
  for (ll i = 1; i <= 2 * n; i += 3) {
    s += "110";
  }
  ll sz = s.size();
  bool ok = false;
  for (ll i = 0; i < sz - n + 1; i++) {
    if (t == s.substr(i, n)) ok = true;
  }
  if (!ok) {
    cout << 0 << endl;
    return 0;
  }

  ll cnt = 0;
  rep(i, n) {
    if (t[i] == '0') cnt++;
  }

  ll ans;
  if (t[n - 1] == '0') {
    ans = 1e10 - cnt + 1;
    cout << ans << endl;
  } else {
    ans = 1e10 - cnt;
    cout << ans << endl;
  }
  return 0;
}