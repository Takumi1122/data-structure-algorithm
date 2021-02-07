#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  ll x, y;
  cin >> x >> y;

  ll ans = 1;
  x *= 2;
  while (x <= y) {
    ans++;
    x *= 2;
  }

  cout << ans << endl;
  return 0;
}