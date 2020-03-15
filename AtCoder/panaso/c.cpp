#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll a, b, c, r, l;
  cin >> a >> b >> c;
  l = (c - (a + b)) * (c - (a + b));
  r = 4 * a * b;

  if (l > r && c - (a + b) > 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}