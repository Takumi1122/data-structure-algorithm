#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int GCD(int a, int b) {
  if (b == 0)
    return a;
  else
    return GCD(b, a % b);
}

int gcd(int a, int b, int c, int n) {
  int g = 0;
  for (int i = 0; i < n; ++i) {
    if (i == 0) {
      g = GCD(g, a);
    } else if (i == 1) {
      g = GCD(g, b);
    } else {
      g = GCD(g, c);
    }
  }
  return g;
}

int main() {
  int n, k;
  ll s = 0;
  cin >> k;
  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j <= k; ++j) {
      for (int t = 1; t <= k; ++t) {
                s += gcd(i, j, t, n);
      }
    }
  }
  cout << s << endl;

  return 0;
}
