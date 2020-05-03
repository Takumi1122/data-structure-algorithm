#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll x;
  cin >> x;
  ll a = 100;
  int y = 0;
  while (a < x) {
    a = a * 1.01;
    y++;
  }
  cout << y << endl;
  return 0;
}