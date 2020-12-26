#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 115 D - Christmas
      https://atcoder.jp/contests/abc115/tasks/abc115_d
*/

ll len[51], pat[51];

ll rec(ll k, ll x) {
  if (x == len[k]) return pat[k];

  ll ans = 0;
  // 下のバン
  x--;
  // 下のk-1バーガー
  if (x > 0) {
    ll l = min(x, len[k - 1]);
    ans += rec(k - 1, l);
    x -= l;
  }
  // 真ん中のパティ
  if (x > 0) {
    ans++;
    x--;
  }
  // 上のk-1バーガー
  if (x > 0) {
    ll l = min(x, len[k - 1]);
    ans += rec(k - 1, l);
    x -= l;
  }

  return ans;
}

int main() {
  ll n, x;
  cin >> n >> x;

  len[0] = pat[0] = 1;
  for (int i = 1; i <= n; i++) {
    len[i] = len[i - 1] * 2 + 3;
    pat[i] = pat[i - 1] * 2 + 1;
  }

  cout << rec(n, x) << endl;
  return 0;
}