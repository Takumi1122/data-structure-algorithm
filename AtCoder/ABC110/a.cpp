#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int ans = max(a * 10 + b + c, a + 10 * b + c);
  ans = max(ans, a + b + 10 * c);
  cout << ans << endl;
  return 0;
}