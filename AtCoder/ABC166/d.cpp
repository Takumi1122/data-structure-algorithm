#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int x;
  cin >> x;
  for (int a = 1; a < 1000; ++a) {
    ll a5 = 1;
    rep(i, 5) a5 *= a;
    for (int b = -1000; b < 1000; ++b) {
      ll b5 = 1;
      rep(i, 5) b5 *= b;
      if (a5 - b5 == x) {
        printf("%d %d\n", a, b);
        return 0;
      }
    }
  }
  return 0;
}
