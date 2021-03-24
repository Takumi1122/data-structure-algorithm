#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int ans = -1001001;
  for (int i = a; i <= b; i++) {
    for (int j = c; j <= d; j++) {
      ans = max(ans, i - j);
    }
  }

  cout << ans << endl;
  return 0;
}