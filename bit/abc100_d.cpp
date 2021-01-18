#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// bit全探索 決め打ち 絶対値
// 絶対値というのは元の数に対して,+1倍,-1倍のどちらか = 2通りしかない

/*
    参考リンク
    ABC 100 D - Patisserie ABC
      https://atcoder.jp/contests/abc100/tasks/abc100_d
*/

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<ll>> a(n, vector<ll>(3));
  rep(i, n) {
    rep(j, 3) {
      ll num;
      cin >> num;
      a[i][j] = num;
    }
  }

  ll ans = 0;
  for (int bit = 0; bit < (1 << 3); ++bit) {
    vector<ll> b;
    rep(i, n) {
      ll tmp = 0;
      rep(j, 3) {
        if (bit & (1 << j))
          tmp += a[i][j];
        else
          tmp -= a[i][j];
      }
      b.push_back(tmp);
    }

    sort(b.begin(), b.end(), greater<ll>());

    ll sum = 0;
    rep(i, m) sum += b[i];
    ans = max(ans, sum);
  }

  cout << ans << endl;
  return 0;
}