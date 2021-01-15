#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int ans = min(abs(a - b) + abs(b - c), abs(a - c) + abs(c - b));
  ans = min(ans, abs(b - a) + abs(a - c));
  cout << ans << endl;
  return 0;
}