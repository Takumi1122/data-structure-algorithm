#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// (Ai - Aj)^2のシグマに関する変形 (j < i)

/*
    参考リンク
    ABC 194 C - Squared Error
      https://atcoder.jp/contests/abc194/tasks/abc194_c
*/

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll sum = 0;
  rep(i, n) sum += a[i];

  ll ans = 0;
  rep(i, n) ans += n * a[i] * a[i];
  ans -= sum * sum;

  cout << ans << endl;
  return 0;
}