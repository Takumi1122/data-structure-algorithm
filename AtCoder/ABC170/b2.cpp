#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int x, y;
  cin >> x >> y;
  for (int c = 0; c <= x; c++) {
    int t = x - c;
    int asi = c * 2 + t * 4;
    if (asi == y) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
