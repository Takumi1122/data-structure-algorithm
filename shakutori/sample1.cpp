#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// O(n)
// 連続する部分列で、その総和がx以下となるものを数え上げ

/*
    参考リンク
    AIZU ONLINE JUDGE
      https://onlinejudge.u-aizu.ac.jp/problems/DSL_3_C
*/

int main() {
  int n, q;
  cin >> n >> q;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  rep(i, q) {
    ll x;
    cin >> x;

    ll res = 0;
    int right = 0;
    ll sum = 0;
    rep(left, n) {
      while (right < n && sum + a[right] <= x) {
        sum += a[right];
        ++right;
      }
      res += (right - left);

      if (right == left)
        ++right;
      else
        sum -= a[left];
    }
    cout << res << endl;
  }
}