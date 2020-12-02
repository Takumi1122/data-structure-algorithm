#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 127 C - Prison
      https://atcoder.jp/contests/abc127/tasks/abc127_c
*/

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> l(m);
  vector<int> r(m);
  rep(i, m) {
    cin >> l[i] >> r[i];
    l[i]--;
    r[i]--;
  }
  vector<int> lr(n + 1);
  rep(i, m) {
    lr[l[i]]++;
    r[i]++;
    lr[r[i]]--;
  }

  rep(i, n) lr[i + 1] += lr[i];
  int ans = 0;
  rep(i, n) {
    if (lr[i] == m) ans++;
  }

  cout << ans << endl;
  return 0;
}