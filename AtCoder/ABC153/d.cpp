#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll h;
  cin >> h;

  ll cnt = 0, teki = 1;
  while (h) {
    h /= 2;
    cnt += teki;
    teki *= 2;
  }
  cout << cnt << endl;
  return 0;
}