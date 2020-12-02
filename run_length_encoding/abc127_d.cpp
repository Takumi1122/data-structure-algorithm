#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using pll = pair<ll, ll>;

// ランレングス圧縮

/*
    参考リンク
    ABC 127 D - Integer Cards
      https://atcoder.jp/contests/abc127/tasks/abc127_d
*/

int main() {
  int n, m;
  cin >> n >> m;
  vector<pll> v;
  rep(i, n) {
    int a;
    cin >> a;
    v.push_back({a, 1});
  }
  rep(i, m) {
    int b, c;
    cin >> b >> c;
    v.push_back({c, b});
  }
  sort(v.begin(), v.end(), greater<pll>());

  ll num = 0;
  ll ans = 0;
  for (auto p : v) {
    if (num + p.second <= n) {
      ans += p.first * p.second;
      num += p.second;
    } else {
      ans += p.first * (n - num);
      num = n;
      break;
    }
  }

  cout << ans << endl;
  return 0;
}