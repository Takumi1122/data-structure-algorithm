#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, k;
  cin >> n >> k;
  vector<double> p(n);
  rep(i, n) {
    cin >> p[i];
    p[i] = (p[i] + 1) / 2;
  }

  vector<double> sum(n + 1);
  rep(i, n) sum[i + 1] = sum[i] + p[i];
  double mx = 0;

  for (int i = 0; i <= n - k; ++i) {
    double var = sum[k + i] - sum[i];
    mx = max(var, mx);
  }

  cout << fixed << setprecision(10) << mx << endl;

  return 0;
}