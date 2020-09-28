#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

#include <atcoder/all>
using namespace atcoder;

int main() {
  int q, n;
  cin >> n >> q;
  dsu ds(n);
  rep(i, q) {
    int t, u, v;
    cin >> t >> u >> v;
    if (t == 0) {
      ds.merge(u, v);
    } else {
      if (ds.same(u, v))
        cout << 1 << endl;
      else
        cout << 0 << endl;
    }
  }
}