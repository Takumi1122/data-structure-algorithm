#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int k;
  cin >> k;
  if (a < b && b < c) {
    cout << "Yes" << endl;
    return 0;
  }
  bool ok = false;

  for (int i = 0; i <= k; i++) {
    int j = k - i;
    int b1 = b;
    int c1 = c;
    if (i >= 1) b1 = b1 * pow(2, i);
    if (j >= 1) c1 = c1 * pow(2, j);
    if (a < b1 && b1 < c1) ok = true;
  }

  if (ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}