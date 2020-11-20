#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  rep(i, n) cin >> p[i];
  int ans = 0;
  rep(i, n - 2) {
    if (p[i] < p[i + 1] && p[i + 1] < p[i + 2]) ans++;
    if (p[i] > p[i + 1] && p[i + 1] > p[i + 2]) ans++;
  }
  cout << ans << endl;
  return 0;
}