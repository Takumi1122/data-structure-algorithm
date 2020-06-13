#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll a, v, b, w, t;
  cin >> a >> v >> b >> w >> t;
  if (w - v >= 0) {
    cout << "NO" << endl;
  } else {
    if (abs(a - b) <= (v - w) * t) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}