#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 決めてから整合性を確認する

int main() {
  int n;
  cin >> n;
  vector<vector<int>> c(n, vector<int>(n));
  rep(i, n) rep(j, n) cin >> c[i][j];

  vector<int> a(n);
  rep(i, n) a[i] = c[i][0];
  int mn = 1001001001;
  rep(i, n) mn = min(mn, a[i]);
  rep(i, n) a[i] -= mn;

  vector<int> b(n);
  rep(i, n) b[i] = c[0][i] - a[0];
  rep(i, n) {
    if (b[i] < 0) {
      cout << "No" << endl;
      return 0;
    }
  }

  rep(i, n) rep(j, n) {
    if (a[i] + b[j] != c[i][j]) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  rep(i, n) cout << a[i] << endl;
  rep(i, n) cout << b[i] << endl;
  return 0;
}