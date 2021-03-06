#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

/*
    参考リンク
    ABC 194 C - Squared Error
      https://atcoder.jp/contests/abc194/tasks/abc194_c
*/

const int MaxA = 200;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<int> d(MaxA * 2 + 1);
  rep(i, n) d[MaxA + a[i]]++;

  ll ans = 0;
  for (int ai = -MaxA; ai <= MaxA; ++ai) {
    for (int aj = -MaxA; aj < ai; ++aj) {
      ll x = ai - aj;
      ans += x * x * d[MaxA + ai] * d[MaxA + aj];
    }
  }

  cout << ans << endl;
  return 0;
}