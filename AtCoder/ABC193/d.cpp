#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 確率
// 数え上げ

/*
    参考リンク
    ABC 193 D - Poker
      https://atcoder.jp/contests/abc193/tasks/abc193_d
*/

int f(string s) {
  vector<int> a(10);
  for (char c : s) a[c - '0']++;
  int res = 0;
  for (int i = 1; i <= 9; ++i) {
    int x = 1;
    rep(j, a[i]) x *= 10;
    res += x * i;
  }
  return res;
}

int main() {
  int k;
  cin >> k;
  string s, t;
  cin >> s >> t;

  vector<int> c(10, k);
  c[0] = 0;
  rep(i, 4) c[s[i] - '0']--;
  rep(i, 4) c[t[i] - '0']--;

  ll cnt = 0;
  for (int a = 1; a <= 9; ++a) {
    for (int b = 1; b <= 9; ++b) {
      s[4] = '0' + a;
      t[4] = '0' + b;
      if (f(s) > f(t)) {
        if (a == b)
          cnt += (ll)c[a] * (c[a] - 1);
        else
          cnt += (ll)c[a] * c[b];
      }
    }
  }

  ll C = 0;
  rep(i, 10) C += c[i];
  ll tot = C * (C - 1);
  double ans = (double)cnt / tot;

  printf("%.10f\n", ans);
  return 0;
}