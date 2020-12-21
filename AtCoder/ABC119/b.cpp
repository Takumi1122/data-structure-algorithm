#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<double> x(n);
  vector<string> u(n);
  rep(i, n) cin >> x[i] >> u[i];

  double ans = 0;
  rep(i, n) {
    if (u[i] == "JPY") {
      ans += x[i];
    } else {
      ans += (x[i] * 380000.0);
    }
  }

  printf("%.15f\n", ans);
  return 0;
}