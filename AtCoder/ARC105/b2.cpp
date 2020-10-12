#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int gcd(int x, int y) { return (x % y) ? gcd(y, x % y) : y; }

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  ll ans = a[0];
  rep(i, n) { ans = gcd(ans, a[i]); }
  cout << ans << endl;

  return 0;
}