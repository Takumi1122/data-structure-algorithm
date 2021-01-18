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
  rep(i, n) {
    while (a[i] % 2 == 0) {
      ans++;
      a[i] /= 2;
    }
  }

  cout << ans << endl;
  return 0;
}