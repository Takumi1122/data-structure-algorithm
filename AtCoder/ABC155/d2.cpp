#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
     「小さい方からK番目の数がX」
  <=>「X未満の数はK個未満で、X以下の数はK個以上」
  <=>「X以下の数がK個以上となる最小のX」
  <=>「X未満の数がK個未満となる最大のX」
*/

// 1つを固定したときに、条件を満たす相方が何個あるのかを求める

/*
    参考リンク
    ABC 155 D - Pairs
      https://atcoder.jp/contests/abc155/tasks/abc155_d
*/

const ll INF = ll(1e18) + 1;

int main() {
  int n;
  ll k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());

  // xを決めうち
  ll l = -INF, r = INF;
  while (l + 1 < r) {
    ll x = (l + r) / 2;
    bool ok = [&] {
      // x以下の個数
      ll tot = 0;

      // a[i]を固定
      rep(i, n) {
        if (a[i] < 0) {
          int l = -1, r = n;
          while (l + 1 < r) {
            int c = (l + r) / 2;
            if (a[i] * a[c] <= x)
              r = c;
            else
              l = c;
          }
          tot += n - r;
        } else {
          int l = -1, r = n;
          while (l + 1 < r) {
            int c = (l + r) / 2;
            if (a[i] * a[c] <= x)
              l = c;
            else
              r = c;
          }
          tot += (l + 1);
        }
        // 自分自身を選ぶ場合を除外
        if (a[i] * a[i] <= x) tot--;
      }

      // 重複を除外
      tot /= 2;

      // x以下の数はk個以上か
      return tot >= k;
    }();

    if (ok)
      r = x;
    else
      l = x;
  }

  cout << r << endl;
  return 0;
}
