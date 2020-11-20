#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> d(n);
  rep(i, n) cin >> d[i];
  sort(d.begin(), d.end());
  int ans = 0;
  int max_d = d.back();
  for (int i = 1; i <= max_d; i++) {
    int id = d.end() - lower_bound(d.begin(), d.end(), i);
    if (id * 2 == n) ans++;
  }
  cout << ans << endl;
  return 0;
}