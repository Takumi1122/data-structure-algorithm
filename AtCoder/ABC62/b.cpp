#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  rep(i, h) cin >> a[i];

  string s = "";
  rep(i, w + 2) s += '#';
  vector<string> ans(h + 2, s);
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) ans[i][j] = a[i - 1][j - 1];
  }

  rep(i, h + 2) cout << ans[i] << endl;
  return 0;
}