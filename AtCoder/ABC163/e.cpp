#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF = 1e18;
const int MX = 2005;
// dp[i][l]:
// 大きい方からi個まで左右を決めて,左をl回,右をr(i-l)回使ったときの最大値
ll dp[MX][MX];
inline void chmax(ll& a, ll b) { a = max(a, b); }

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  dp[0][0] = 0;
  vector<P> p;
  rep(i, n) p.emplace_back(a[i], i);
  sort(p.rbegin(), p.rend());
  rep(i, n) {
    int pi = p[i].second;
    rep(l, i + 1) {
      int r = i - l;
      chmax(dp[i + 1][l + 1], dp[i][l] + ll(pi - l) * a[pi]);
      chmax(dp[i + 1][l], dp[i][l] + ll((n - r - 1) - pi) * a[pi]);
    }
  }

  ll ans = 0;
  rep(i, n + 1) chmax(ans, dp[n][i]);
  cout << ans << endl;
  return 0;
}