#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b;
  cin >> a >> b;
  ll f = 2 * a + 100;
  ll ans = f - b;
  cout << ans << endl;
  return 0;
}