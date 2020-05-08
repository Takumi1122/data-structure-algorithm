#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int x;
  cin >> x;
  while (1) {
    bool ok = true;
    for (int i = 2; i < x; ++i) {
      if (x % i == 0) {
        ok = false;
        break;
      }
    }
    if (ok) break;
    ++x;
  }
  cout << x << endl;
  return 0;
}
