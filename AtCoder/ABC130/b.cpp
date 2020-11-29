#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> l(n);
  rep(i, n) cin >> l[i];

  int d = 0;
  int ans = 1;
  rep(i, n) {
    d += l[i];
    if (d <= x) {
      ans++;
    } else {
      break;
    }
  }

  cout << ans << endl;
  return 0;
}