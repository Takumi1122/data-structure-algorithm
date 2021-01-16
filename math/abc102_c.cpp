#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 中央値 式変形
// |x - a1| + |x - a2| + ... + |x - an| の最小値は x が ai の中央値の時

/*
    参考リンク
    ABC 102 C - Linear Approximation
      https://atcoder.jp/contests/abc102/tasks/arc100_a
*/

int main() {
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  rep(i, n) {
    cin >> a[i];
    b[i] = a[i] - i;
  }

  sort(b.begin(), b.end());
  ll x = b[n / 2];

  ll ans = 0;
  rep(i, n) {
    ans += max(x - b[i], -x + b[i]);  // |A| = max(A, -A)
  }

  cout << ans << endl;
  return 0;
}