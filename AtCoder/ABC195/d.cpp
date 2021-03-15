#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> w(n), v(n);
  rep(i, n) cin >> w[i] >> v[i];
  vector<int> x(m);
  rep(i, m) cin >> x[i];

  rep(i, q) {
    int l, r;
    cin >> l >> r;
    vector<int> a;
    rep(i, l - 1) a.push_back(x[i]);
    for (int i = r; i < m; i++) a.push_back(x[i]);
    sort(a.begin(), a.end());
    vector<P> b(n);
    rep(i, n) b[i] = P(v[i], w[i]);
    sort(b.begin(), b.end(), greater<P>());
    int ans = 0;
    rep(i, n) {
      int v = b[i].first;
      int w = b[i].second;
      rep(j, a.size()) {
        if (a[j] >= w) {
          ans += v;
          a.erase(a.begin() + j);
          break;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}