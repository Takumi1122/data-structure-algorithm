#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m), b(m);
  rep(i, m) cin >> a[i] >> b[i];
  int k;
  cin >> k;
  vector<int> c(k), d(k);
  rep(i, k) cin >> c[i] >> d[i];

  int ans = 0;
  for (int bit = 0; bit < (1 << k); ++bit) {
    int cnt = 0;
    set<int> st;

    rep(i, k) {
      if (bit & (1 << i)) {
        st.insert(c[i]);
      } else {
        st.insert(d[i]);
      }
    }

    rep(i, m) {
      if (st.count(a[i]) && st.count(b[i])) cnt++;
    }
    ans = max(ans, cnt);
  }

  cout << ans << endl;
  return 0;
}