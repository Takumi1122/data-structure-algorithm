#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// O(n * log(n))

/*
    参考リンク
    ABC 150 D - Semi Common Multiple
      https://atcoder.jp/contests/abc150/tasks/abc150_d
*/

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll solve(int n, ll m, vector<ll> &a) {
  // 2で割れるだけ割る(割れる回数が異なったらダメ)
  while (a[0] % 2 == 0) {
    rep(i, n) {
      if (a[i] % 2 != 0) return 0;
      a[i] /= 2;
    }
    m /= 2;
  }
  rep(i, n) if (a[i] % 2 == 0) return 0;

  // lcm
  ll lc = 1;
  rep(i, n) {
    lc = lcm(lc, a[i]);
    if (lc > m) return 0;
  }
  return (m / lc + 1) / 2;
}

int main() {
  int n;
  ll m;
  cin >> n >> m;
  vector<ll> a(n);

  // あらかじめaは一回2で割っておく
  rep(i, n) cin >> a[i], a[i] /= 2;
  cout << solve(n, m, a) << endl;
}