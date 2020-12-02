#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 178 F - Contrast
      https://atcoder.jp/contests/abc178/tasks/abc178_f
*/

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];

  vector<int> ar(n + 1, -1), bl(n + 1, -1);
  rep(i, n) ar[a[i]] = i;
  for (int i = n - 1; i >= 0; --i) bl[b[i]] = i;

  int d = 0;
  for (int i = 1; i <= n; ++i) {
    if (ar[i] == -1 || bl[i] == -1) continue;
    d = max(d, ar[i] - bl[i] + 1);
  }

  rotate(b.begin(), b.begin() + n - d, b.end());

  rep(i, n) {
    if (a[i] == b[i]) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  rep(i, n) std::cout << b[i] << endl;
  return 0;
}