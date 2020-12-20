#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// シグマの式変形
// ソートすることで絶対値を外せる
// 各要素の寄与度を考える

/*
    参考リンク
    ABC 186 D - Sum of difference
      https://atcoder.jp/contests/abc186/tasks/abc186_d
*/

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  sort(a.begin(), a.end());

  vector<ll> s(n + 1, 0);
  rep(i, n) s[i + 1] = s[i] + a[i];

  ll ans = 0;
  rep(i, n) ans += a[i] * (2 * i - n + 1);
  cout << ans << endl;
  return 0;
}