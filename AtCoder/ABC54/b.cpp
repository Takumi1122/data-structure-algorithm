#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n), b(m);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];

  rep(i, n - m + 1) {
    rep(j, n - m + 1) {
      bool ok = true;
      rep(k, m) rep(l, m) {
        if (a[i + k][j + l] != b[k][l]) {
          ok = false;
        }
      }
      if (ok) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
  return 0;
}