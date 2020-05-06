#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> h(n);
  rep(i, n) cin >> h[i];
  vector<vector<int> > g(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  int ans = 0;
  rep(i, n) {
    if (g[i].size() == 0) {
      ans++;
      continue;
    }
    int cnt = 0;
    for (int j = 0; j < g[i].size(); j++) {
      if (h[i] > h[g[i][j]]) {
        cnt++;
      }
    }
    if (cnt == g[i].size()) ans++;
  }
  cout << ans << endl;
  return 0;
}