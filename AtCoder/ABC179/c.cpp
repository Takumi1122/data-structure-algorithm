#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  ll ans = 0;
  for (int i = 1; i <= n - 1; i++) {
    for (int j = 1; j * j <= i; j++) {
      if (i % j == 0 && i / j != j) ans += 2;
      if (i % j == 0 && i / j == j) ans += 1;
    }
  }

  cout << ans << endl;
  return 0;
}