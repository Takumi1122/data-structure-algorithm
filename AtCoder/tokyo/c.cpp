#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  vector<int> anow(n);
  anow = a;
  rep(i, k) {
    vector<int> ans(n, 1);
    rep(j, n) rep(t, anow[j]) {
      if (j - t - 1 >= 0) ans[j - t - 1]++;
      if (j + t + 1 <= n) ans[j + t + 1]++;
    }
    anow = ans;
  }
  rep(i, n) cout << anow[i] << endl;
  return 0;
}