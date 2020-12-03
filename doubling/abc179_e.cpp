#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC179 E - Sequence Sum
      https://atcoder.jp/contests/abc179/tasks/abc179_e
*/

int main() {
  ll n, x, m;
  cin >> n >> x >> m;

  const int logn = 60;
  // doubling[k][i]: i(mod M)から2^kステップ進んだ先の値
  // sum[k][i]: i(mod M)から2^k項分の総和
  vector<vector<ll>> doubling(logn, vector<ll>(m));
  vector<vector<ll>> sum(logn, vector<ll>(m));
  for (ll i = 0; i < m; i++) {
    doubling[0][i] = i * i % m;
    sum[0][i] = i;
  }

  rep(k, logn - 1) {
    rep(i, m) {
      doubling[k + 1][i] = doubling[k][doubling[k][i]];
      sum[k + 1][i] = sum[k][i] + sum[k][doubling[k][i]];
    }
  }

  ll ans = 0;
  ll now = x;
  for (int k = logn; k >= 0; --k) {
    if (n & (1LL << k)) {
      ans += sum[k][now];
      now = doubling[k][now];
    }
  }

  cout << ans << endl;
  return 0;
}