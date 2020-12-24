#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 区間

/*
    参考リンク
    ABC 117 C - Streamline
      https://atcoder.jp/contests/abc117/tasks/abc117_c
*/

int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> x(m);
  rep(i, m) cin >> x[i];

  sort(x.begin(), x.end());
  vector<ll> abx(m - 1);
  rep(i, m - 1) abx[i] = abs(x[i] - x[i + 1]);
  sort(abx.begin(), abx.end(), greater<ll>());

  ll ans = 0;
  for (int i = n - 1; i < m - 1; i++) {
    ans += abx[i];
  }
  cout << ans << endl;
  return 0;
}