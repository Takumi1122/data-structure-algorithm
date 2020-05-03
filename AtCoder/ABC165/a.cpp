#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int k, a, b;
  cin >> k;
  cin >> a >> b;
  bool ok = false;
  for (int i = a; i <= b; i++) {
    if (i % k == 0) ok = true;
  }
  if (ok) {
    cout << "OK" << endl;
  } else {
    cout << "NG" << endl;
  }
  return 0;
}