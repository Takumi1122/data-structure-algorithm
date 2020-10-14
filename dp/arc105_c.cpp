#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ARC 105 C - Camels and Bridge
      https://atcoder.jp/contests/arc105/tasks/arc105_c
*/

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

ll solve() {
  int n, m;
  cin >> n >> m;
  vector<ll> w(n);
  ll maxW = 0;
  rep(i, n) {
    cin >> w[i];
    chmax(maxW, w[i]);
  }
  vector<ll> l(m), v(m);
  rep(i, m) {
    cin >> l[i] >> v[i];
    if (v[i] < maxW) return -1;
  }

  // 前処理
  // dist[bit] : M組の橋のうち、重さの耐荷重が
  // W(bit)未満であるようなものの中での長さの最大値
  vector<ll> dist(1 << n, 0);
  rep(bit, 1 << n) {
    ll W = 0;
    rep(i, n) {
      if (bit & (1 << i)) W += w[i];
    }
    rep(i, m) {
      if (v[i] < W) {
        chmax(dist[bit], l[i]);
      }
    }
  }

  // DP
  ll res = 1LL << 60;
  vector<int> ids(n);
  iota(ids.begin(), ids.end(), 0);
  do {
    vector<ll> dp(n, 0);
    for (int i = 1; i < n; ++i) {
      int bit = (1 << ids[i]);
      for (int j = i - 1; j >= 0; --j) {
        bit |= (1 << ids[j]);
        chmax(dp[i], dp[j] + dist[bit]);
      }
    }
    chmin(res, dp[n - 1]);
  } while (next_permutation(ids.begin(), ids.end()));

  return res;
}

int main() { cout << solve() << endl; }