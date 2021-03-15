#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int a, b, w;
  cin >> a >> b >> w;

  int mn = 1e9, mx = 0;
  for (int n = 1; n <= 1000000; n++) {
    if (a * n <= 1000 * w && 1000 * w <= b * n) {
      mn = min(mn, n);
      mx = max(mx, n);
    }
  }

  if (mx == 0)
    cout << "UNSATISFIABLE" << endl;
  else
    cout << mn << " " << mx << endl;
  return 0;
}