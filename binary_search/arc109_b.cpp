#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

/*
    参考リンク
    ARC 109 B - log
      https://atcoder.jp/contests/arc109/tasks/arc109_b
*/

int main() {
  ll n;
  cin >> n;

  ll l = 0, r = 2e9;
  while (r - l > 1) {
    ll m = (l + r) / 2;
    (m * (m + 1) / 2 <= n + 1 ? l : r) = m;
  }

  cout << n - l + 1 << endl;
  return 0;
}
