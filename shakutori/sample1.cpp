#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// o(n)

int main() {
  int n, q;
  cin >> n >> q;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  /* q 回分のクエリを処理 */
  rep(i, q) {
    ll x;
    cin >> x;

    /* 合計値 */
    ll res = 0;

    /* 区間の左端 left で場合分け */
    int right = 0;      // 毎回 right を使い回すようにする
    ll sum = 0;  // sum も使い回す
    rep(left, n) {
      /* sum に a[right] を加えても大丈夫なら right を動かす */
      while (right < n && sum + a[right] <= x) {
        sum += a[right];
        ++right;
      }

      /* break した状態で right は条件を満たす最大 */
      res += (right - left);

      /* left をインクリメントする準備 */
      if (right == left)
        ++right;  // right が left に重なったら right も動かす
      else
        sum -= a[left];  // left のみがインクリメントされるので sum から a[left]を引く
    }
    cout << res << endl;
  }
}