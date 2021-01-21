#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int a, b, c, k;
  cin >> a >> b >> c >> k;

  int ans =
      max({a * (1 << k) + b + c, a + b * (1 << k) + c, a + b + c * (1 << k)});
  cout << ans << endl;
  return 0;
}