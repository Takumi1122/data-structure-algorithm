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

  set<int> r;
  set<int> c;

  rep(i, h) {
    bool ok = true;
    rep(j, w) {
      if (a[i][j] == '#') ok = false;
    }
    if (ok) r.insert(i);
  }

  rep(j, w) {
    bool ok = true;
    rep(i, h) {
      if (a[i][j] == '#') ok = false;
    }
    if (ok) c.insert(j);
  }

  rep(i, h) {
    if (r.count(i)) continue;
    rep(j, w) {
      if (c.count(j)) continue;
      cout << a[i][j];
    }
    cout << endl;
  }

  return 0;
}