#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b, c, k;
  int cnt = 0;
  cin >> a >> b >> c >> k;

  while (a >= b) {
    cnt++;
    b *= 2;
  }
  while (b >= c) {
    cnt++;
    c *= 2;
  }

  if (cnt <= k)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}