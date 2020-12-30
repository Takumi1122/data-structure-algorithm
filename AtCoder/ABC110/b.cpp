#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m, X, Y;
  cin >> n >> m >> X >> Y;
  vector<int> x(n), y(m);
  rep(i, n) cin >> x[i];
  rep(i, m) cin >> y[i];

  bool war = true;
  for (int i = X + 1; i <= Y; i++) {
    bool ok = true;
    rep(j, n) if (x[j] >= i) ok = false;
    rep(j, m) if (y[j] < i) ok = false;
    if (ok) {
      war = false;
      break;
    }
  }

  if (war) {
    cout << "War" << endl;
  } else {
    cout << "No War" << endl;
  }
  return 0;
}