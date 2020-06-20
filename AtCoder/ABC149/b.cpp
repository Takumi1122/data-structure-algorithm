#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll a, b, k;
  cin >> a >> b >> k;
  if (a >= k) {
    cout << a - k << " " << b << endl;
    return 0;
  } else {
    k -= a;
    if (b - k > 0) {
      cout << 0 << " " << b - k << endl;
      return 0;
    }
  }
  cout << 0 << " " << 0 << endl;
}