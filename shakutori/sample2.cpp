#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 連続する部分列で、その総和がx以上となるもののうち、最小の長さ

int main() {
  int q;
  cin >> q;

  rep(query, q) {
    int n;
    cin >> n;
    ll x;
    cin >> x;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    int res = n + 1;

    int right = 0;
    ll sum = 0;
    rep(left, n) {
      while (right < n && sum < x) {
        sum += a[right];
        ++right;
      }

      if (sum < x) break;
      res = min(res, right - left);

      if (right == left)
        ++right;
      else
        sum -= a[left];
    }

    if (res < n + 1)
      cout << res << endl;
    else
      cout << 0 << endl;
  }
}