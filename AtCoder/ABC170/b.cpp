#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int x, y;
  cin >> x >> y;
  if (y % 2 == 1) {
    cout << "No" << endl;
    return 0;
  }
  for (int i = 0; i <= x; i++) {
    int sum = (x - i) * 2 + 4 * i;
    if (y == sum) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}