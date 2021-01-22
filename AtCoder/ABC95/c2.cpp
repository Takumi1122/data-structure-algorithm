#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  int ans1 = a * x + b * y;
  int ans2 = 2 * c * max(x, y);
  int p = x < y ? b : a;
  int ans3 = 2 * c * min(x, y) + p * abs(x - y);
  int ans = min({ans1, ans2, ans3});

  cout << ans << endl;
  return 0;
}