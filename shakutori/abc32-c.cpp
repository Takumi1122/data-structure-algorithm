#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  /* 入力受け取り */
  int n;
  ll k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  /* 0 があったら n をリターン */
  rep(i, n) {
    if (a[i] == 0) {
      cout << n << endl;
      return 0;
    }
  }

  /* しゃくとり法 */
  int res = 0;
  int right = 0;
  ll mul = 1;
  rep(left, n) {
    while (right < n && mul * a[right] <= k) {
      mul *= a[right];
      ++right;
    }
    res = max(res, right - left);  // 更新
    if (left == right)
      ++right;
    else
      mul /= a[left];  // left を除く
  }

  cout << res << endl;
}