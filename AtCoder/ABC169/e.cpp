#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> ls(n), rs(n);
  rep(i, n) cin >> ls[i] >> rs[i];
  sort(ls.begin(), ls.end());
  sort(rs.begin(), rs.end());
  int ans = 0;
  if (n % 2 == 1) {
    int l = ls[n / 2];
    int r = rs[n / 2];
    ans = r - l + 1;
  } else {
    int l2 = ls[n / 2 - 1] + ls[n / 2];
    int r2 = rs[n / 2 - 1] + rs[n / 2];
    ans = r2 - l2 + 1;
  }
  cout << ans << endl;
  return 0;
}
