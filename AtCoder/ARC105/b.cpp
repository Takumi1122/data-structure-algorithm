#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  int mx = 0;
  int mn = 1e9 + 10;
  rep(i, n) {
    cin >> a[i];
    mx = max(mx, a[i]);
    mn = min(mn, a[i]);
  }

  while (mx != mn) {
    rep(i, n) {
      if (a[i] == mx) a[i] = mx - mn;
    }
    mx = 0;
    mn = 1e9 + 10;
    rep(i, n) {
      mx = max(mx, a[i]);
      mn = min(mn, a[i]);
    }
  }

  cout << a[0] << endl;

  return 0;
}