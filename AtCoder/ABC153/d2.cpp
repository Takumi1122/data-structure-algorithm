#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll f(ll x) {
  if (x == 1) return 1;
  ll a = f(x / 2);
  return a * 2 + 1;
}

int main() {
  ll h;
  cin >> h;
  cout << f(h) << endl;
  return 0;
}
