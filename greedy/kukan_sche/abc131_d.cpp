#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 131 D - Megalomania
      https://atcoder.jp/contests/abc131/tasks/abc131_d
*/

int main() {
  int n;
  cin >> n;
  vector<P> st(n);
  rep(i, n) cin >> st[i].second >> st[i].first;
  sort(st.begin(), st.end());

  ll ans = 0;
  ll t = 0;
  rep(i, n) {
    if (t + st[i].second <= st[i].first) {
      ans++;
      t += st[i].second;
    }
  }

  if (ans == n) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}