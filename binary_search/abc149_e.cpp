#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 累積和 + 二分探索 + lower_bound
// O(n * log(n) * log(A_max))

/*
    参考リンク
    ABC 149 E - Handshake
      https://atcoder.jp/contests/abc149/tasks/abc149_e
*/

int main() {
  int n;
  ll m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  sort(a.begin(), a.end());

  vector<ll> s(n + 1);
  rep(i, n) s[i + 1] = s[i] + a[i];

  // 握手で得られる幸福度の最小値をxとする
  auto calc = [&](int x) {
    // num : x以上の幸福度が得られる握手の数
    // tot : num種類の握手をしたときの幸福度の合計
    ll tot = 0, num = 0;
    rep(i, n) {
      int j = lower_bound(a.begin(), a.end(), x - a[i]) - a.begin();
      num += n - j;
      tot += s[n] - s[j];
      tot += a[i] * ll(n - j);
    }
    return make_pair(tot, num);
  };

  int l = 0, r = 200005;
  while (l + 1 < r) {
    int c = (l + r) >> 1;
    if (calc(c).second >= m)
      l = c;
    else
      r = c;
  }

  auto p = calc(l);
  ll ans = p.first;
  // 同じ幸福度の握手について
  ans -= (p.second - m) * l;

  cout << ans << endl;
  return 0;
}
