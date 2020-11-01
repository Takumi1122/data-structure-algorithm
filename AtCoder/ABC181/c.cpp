#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<ll> x(n);
  vector<ll> y(n);
  rep(i, n) cin >> x[i] >> y[i];
  bool ok = false;

  rep(i, n) rep(j, n) rep(k, n) {
    if (i == j || j == k || k == i) continue;
    if ((y[i] - y[j]) * (x[j] - x[k]) == (y[j] - y[k]) * (x[i] - x[j])) {
      ok = true;
    }
  }

  if (ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}