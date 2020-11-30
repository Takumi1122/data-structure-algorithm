#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> w(n);
  rep(i, n) cin >> w[i];
  int sum1 = 0;
  int sum2 = 0;
  rep(i, n) sum2 += w[i];
  int ans = 1e9;
  rep(i, n - 1) {
    sum1 += w[i];
    sum2 -= w[i];
    ans = min(ans, abs(sum1 - sum2));
  }
  cout << ans << endl;
  return 0;
}