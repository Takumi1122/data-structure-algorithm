#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  int ans = 0;
  rep(i, n) {
    int mn = 1e9 + 5;
    for (int j = i; j < n; j++) {
      mn = min(mn, a[j]);
      ans = max(ans, abs(i - j - 1) * mn);
    }
  }

  cout << ans << endl;
  return 0;
}