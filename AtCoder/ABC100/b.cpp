#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int d, n;
  cin >> d >> n;

  if (d == 0) {
    if (n == 100) {
      cout << 101 << endl;
    } else {
      cout << n << endl;
    }
  } else if (d == 1) {
    if (n == 100) {
      cout << 10100 << endl;
    } else {
      cout << 100 * n << endl;
    }
  } else {
    if (n == 100) {
      cout << 1010000 << endl;
    } else {
      cout << 10000 * n << endl;
    }
  }
  return 0;
}