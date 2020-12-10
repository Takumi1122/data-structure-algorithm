#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, k;
  cin >> n >> k;

  vector<bool> a(n, true);
  rep(i, k) {
    int d;
    cin >> d;
    rep(j, d) {
      int x;
      cin >> x;
      x--;
      a[x] = false;
    }
  }

  int ans = 0;
  rep(i, n) {
    if (a[i]) ans++;
  }
  cout << ans << endl;
  return 0;
}