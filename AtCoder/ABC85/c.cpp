#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  ll n, y;
  cin >> n >> y;

  for (ll i = 0; i <= n; i++) {
    for (ll j = 0; j <= n; j++) {
      if (n - i - j < 0) continue;
      ll sum = 10000 * i + 5000 * j + 1000 * (n - i - j);
      if (y == sum) {
        cout << i << " " << j << " " << n - i - j << endl;
        return 0;
      }
    }
  }

  cout << -1 << " " << -1 << " " << -1 << endl;
  return 0;
}