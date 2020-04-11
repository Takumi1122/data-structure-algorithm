#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, k;
  cin >> n >> k;
  if (n % k == 0) {
    cout << 0 << endl;
  } else if (n <= k) {
    cout << min(n, abs(n - k)) << endl;
  } else {
    ll a = n % k;
    cout << min(a, abs(a - k)) << endl;
  }
  return 0;
}