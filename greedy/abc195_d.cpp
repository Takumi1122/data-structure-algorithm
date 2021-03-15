#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

// どのような箱詰め方法から始めても、価値の合計を減らすことなくこの詰め方（貪欲法による詰め方）に変更できる

/*
    参考リンク
    ABC 195 D - Shipping Center
      https://atcoder.jp/contests/abc195/tasks/abc195_d
*/

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> w(n), v(n);
  rep(i, n) cin >> w[i] >> v[i];
  vector<int> x(m);
  rep(i, m) cin >> x[i];

  rep(qi, q) {
    int l, r;
    cin >> l >> r;
    --l;
    --r;

    vector<int> as;
    rep(i, m) if (i < l || r < i) as.push_back(x[i]);
    sort(as.begin(), as.end());
    vector<bool> used(n);
    int ans = 0;

    for (int a : as) {
      P best(-1, -1);
      rep(i, n) {
        if (used[i]) continue;
        if (w[i] > a) continue;
        best = max(best, P(v[i], i));
      }
      int i = best.second;
      if (i == -1) continue;
      used[i] = true;
      ans += v[i];
    }
    cout << ans << endl;
  }
  return 0;
}