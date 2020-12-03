#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int k, x;
  cin >> k >> x;

  if (500 * k >= x) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}