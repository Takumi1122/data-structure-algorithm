#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 164 D - Multiple of 2019
      https://atcoder.jp/contests/abc164/tasks/abc164_d
*/

int main() {
  string s;
  cin >> s;

  int n = s.size();
  vector<ll> val(2019, 0);
  ll fac = 1;
  ll now = 0;
  val[now]++;
  rep(i, n) {
    ll add = s[n - 1 - i] - '0';
    now = (now + fac * add) % 2019;
    fac = (fac * 10) % 2019;
    val[now]++;
  }

  ll ans = 0;
  rep(i, val.size()) ans += val[i] * (val[i] - 1) / 2;
  cout << ans << endl;
  return 0;
}