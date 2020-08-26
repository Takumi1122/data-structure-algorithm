#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, x, t;
  cin >> n >> x >> t;

  if (n <= x) {
    cout << t << endl;
    return 0;
  }
  int c = (n + x - 1) / x;
  int ans = 0;
  ans += c * t;

  cout << ans << endl;
  return 0;
}