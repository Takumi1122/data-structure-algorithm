#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> h(n);
  vector<bool> ok(n, true);
  rep(i, n) cin >> h[i];
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    if (h[a] <= h[b]) ok[a] = false;
    if (h[b] <= h[a]) ok[b] = false;
  }
  int ans = 0;
  rep(i, n) if (ok[i]) ans++;
  cout << ans << endl;
  return 0;
}
