#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, t, a;
  cin >> n >> t >> a;
  vector<int> h(n);
  rep(i, n) cin >> h[i];

  int ans = 0;
  double mn = 1e9;
  rep(i, n) {
    double tem = t - h[i] * 0.006;
    if (abs(a - tem) < mn) {
      ans = i + 1;
      mn = abs(a - tem);
    }
  }

  cout << ans << endl;
  return 0;
}