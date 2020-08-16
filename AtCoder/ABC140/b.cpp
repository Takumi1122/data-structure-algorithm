#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  vector<int> c(n - 1);
  rep(i, n) {
    int an;
    cin >> an;
    an--;
    a[i] = an;
  }
  rep(i, n) cin >> b[i];
  rep(i, n - 1) cin >> c[i];

  int ans = 0;
  rep(i, n) {
    ans += b[a[i]];
    if (i == 0) continue;
    if (a[i - 1] + 1 == a[i]) ans += c[a[i - 1]];
  }

  cout << ans << endl;
  return 0;
}