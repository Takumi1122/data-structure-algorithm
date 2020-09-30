#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

#include <atcoder/all>
using namespace atcoder;

// dsu 0-index

int main() {
  int n, m;
  cin >> n >> m;
  dsu ds(n);

  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    ds.merge(a, b);
  }

  vector<vector<int>> g = ds.groups();
  cout << g.size() - 1 << endl;
  return 0;
}