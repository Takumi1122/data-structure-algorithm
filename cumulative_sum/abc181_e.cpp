#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 左右からの累積和

/*
    参考リンク
    ABC 181 E - Transformable Teacher
      https://atcoder.jp/contests/abc181/tasks/abc181_e
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

const ll INF = 1LL << 60;

int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> h(n), W(m);
  rep(i, n) cin >> h[i];
  rep(i, m) cin >> W[i];
  sort(h.begin(), h.end());

  vector<ll> left(n + 1, 0), right(n + 1, 0);
  for (int i = 2; i < n; i += 2) {
    left[i] = left[i - 2] + h[i - 1] - h[i - 2];
    right[i] = right[i - 2] + h[n - i + 1] - h[n - i];
  }
  ll res = INF;
  for (auto w : W) {
    int i = lower_bound(h.begin(), h.end(), w) - h.begin();
    if (i % 2 == 0)
      chmin(res, left[i] + right[n - i - 1] + h[i] - w);
    else
      chmin(res, left[i - 1] + right[n - i] + w - h[i - 1]);
  }
  cout << res << endl;
}