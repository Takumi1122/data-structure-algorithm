#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int n, d, x;
  cin >> n >> d >> x;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  int ans = x;
  rep(i, n) {
    int day = 1;
    while (day <= d) {
      ans++;
      day += a[i];
    }
  }

  cout << ans << endl;
  return 0;
}