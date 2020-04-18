#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll h;
  ll c = 0, p = 1;
  cin >> h;
  while (h) {
    h /= 2;
    c = c + p;
    p *= 2;
  }
  cout << c << endl;
  return 0;
}