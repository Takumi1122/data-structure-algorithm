#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, k;
  cin >> n >> k;
  ll a = n % k;
  ll ans = min(a, k - a);
  cout << ans << endl;
  return 0;
}
