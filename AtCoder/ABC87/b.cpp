#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int a, b, c, x;
  cin >> a >> b >> c >> x;

  int ans = 0;
  for (int i = 0; i <= a; i++) {
    for (int j = 0; j <= b; j++) {
      for (int k = 0; k <= c; k++) {
        int sum = 500 * i + 100 * j + 50 * k;
        if (sum == x) ans++;
      }
    }
  }

  cout << ans << endl;
  return 0;
}