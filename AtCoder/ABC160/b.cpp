#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  int h = 0;
  ll x;
  cin >> x;
  while (x > 0) {
    if (x - 500 >= 0) {
      h += 1000;
      x -= 500;
    } else if (x - 100 >= 0) {
      h += 100;
      x -= 100;
    } else if (x - 50 >= 0) {
      h += 50;
      x -= 50;
    } else if (x - 10 >= 0) {
      h += 10;
      x -= 10;
    } else if (x - 5 >= 0) {
      h += 5;
      x -= 5;
    } else {
      break;
    }
  }
  cout << h << endl;
  return 0;
}