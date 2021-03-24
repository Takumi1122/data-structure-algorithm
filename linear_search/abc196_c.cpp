#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 全探索 O(√n)

/*
    参考リンク
    ABC 196 C - Doubled
      https://atcoder.jp/contests/abc196/tasks/abc196_c
*/

ll f(ll x) {
  string s = to_string(x);
  return stoll(s + s);
}

int main() {
  ll n;
  cin >> n;

  ll ans = 0;
  for (ll i = 1; i <= 1000000; i++) {
    if (f(i) <= n)
      ans++;
    else
      break;
  }

  cout << ans << endl;
  return 0;
}