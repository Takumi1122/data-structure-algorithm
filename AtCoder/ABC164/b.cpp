#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  bool bl = false;
  while (a > 0 && c > 0) {
    c = c - b;
    if (c <= 0) bl = true;
    a = a - d;
  }

  if (bl) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}