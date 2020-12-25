#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 185 D - Stamp
      https://atcoder.jp/contests/abc185/tasks/abc185_d
*/

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  rep(i, m) cin >> a[i];

  sort(a.begin(), a.end());
  a.push_back(n + 1);

  int now = 1;
  vector<int> s;
  rep(i, m + 1) {
    int w = a[i] - now;
    if (w != 0) s.push_back(w);
    now = a[i] + 1;
  }

  int k = n;
  for (int w : s) k = min(k, w);

  int ans = 0;
  for (int w : s) ans += (w + k - 1) / k;

  cout << ans << endl;
  return 0;
}