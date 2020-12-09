#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  rep(i, m) cin >> a[i];

  ll sum = 0;
  ll ans = -1;
  rep(i, m) sum += a[i];
  if (sum <= n) ans = n - sum;
  cout << ans << endl;
  return 0;
}