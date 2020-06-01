#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll a;
  double b;
  cin >> a >> b;
  ll ans1 = b * 100 + 0.5;
  ll ans2 = (a * ans1) / 100;
  cout << ans2 << endl;
  return 0;
}