#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> x(n);
  rep(i, n) cin >> x[i];

  int ans = 0;
  rep(i, n) ans += min(2 * abs(x[i] - 0), 2 * abs(x[i] - k));

  cout << ans << endl;
  return 0;
}