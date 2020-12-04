#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  rep(i, n) cin >> p[i];

  int ans = 0;
  int mn = 1e9;
  rep(i, n) {
    mn = min(mn, p[i]);
    if (mn == p[i]) ans++;
  }

  cout << ans << endl;
  return 0;
}
