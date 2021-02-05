#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 貪欲法

/*
    参考リンク
    ABC 85 D - Katana Thrower
      https://atcoder.jp/contests/abc085/tasks/abc085_d
*/

int main() {
  int n, h;
  cin >> n >> h;
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];

  sort(a.begin(), a.end(), greater<int>());
  sort(b.begin(), b.end(), greater<int>());

  int mx = a[0];
  int cnt = 0;
  rep(i, n) {
    if (mx >= b[i]) break;
    if (h <= 0) {
      cout << cnt << endl;
      return 0;
    }
    h -= b[i];
    cnt++;
  }
  cnt += (h + mx - 1) / mx;

  cout << cnt << endl;
  return 0;
}