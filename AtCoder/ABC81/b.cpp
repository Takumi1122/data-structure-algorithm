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
  while (a[0] % 2 == 0) {
    bool ok = true;
    rep(i, n) {
      if (a[i] % 2 == 0) {
        a[i] /= 2;
      } else {
        ok = false;
      }
    }
    if (!ok) break;
    ans++;
  }

  cout << ans << endl;
  return 0;
}