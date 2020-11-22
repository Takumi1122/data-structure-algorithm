#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 半分全列挙 O(n * 2^(n/2))

/*
    参考リンク
    ABC 184 F - Programming Contest
      https://atcoder.jp/contests/abc184/tasks/abc184_f
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

int main() {
  ll n, t;
  cin >> n >> t;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  // 後半半分を列挙
  vector<ll> q;
  for (int bit = 0; bit < (1 << (n - n / 2)); ++bit) {
    ll sum = 0;
    rep(i, n - n / 2) if (bit & (1LL << i)) sum += a[i + n / 2];
    q.push_back(sum);
  }
  sort(q.begin(), q.end());
  q.push_back(1LL << 60);

  // 前半を固定して二分探索
  ll ans = 0;
  for (int bit = 0; bit < (1 << (n / 2)); ++bit) {
    ll sum = 0;
    rep(i, n / 2) if (bit & (1LL << i)) sum += a[i];
    if (sum > t) continue;
    auto it = upper_bound(q.begin(), q.end(), t - sum) - q.begin();
    --it;
    chmax(ans, sum + q[it]);
  }
  cout << ans << endl;
}
