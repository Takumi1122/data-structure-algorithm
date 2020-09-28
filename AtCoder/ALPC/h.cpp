#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

#include <atcoder/all>
using namespace atcoder;

int main() {
  int n, d;
  cin >> n >> d;
  vector<int> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];

  // ts[i] = (i-th flag is located on x[i])
  two_sat ts(n);

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (abs(x[i] - x[j]) < d) {
        // cannot use both of x[i] and x[j]
        ts.add_clause(i, false, j, false);
      }
      if (abs(x[i] - y[j]) < d) {
        ts.add_clause(i, false, j, true);
      }
      if (abs(y[i] - x[j]) < d) {
        ts.add_clause(i, true, j, false);
      }
      if (abs(y[i] - y[j]) < d) {
        ts.add_clause(i, true, j, true);
      }
    }
  }

  if (!ts.satisfiable()) {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  auto answer = ts.answer();
  rep(i, n) {
    if (answer[i])
      cout << x[i] << endl;
    else
      cout << y[i] << endl;
  }

  return 0;
}