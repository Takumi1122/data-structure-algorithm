#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 162 D - RGB Triplets
      https://atcoder.jp/contests/abc162/tasks/abc162_d
*/

int main() {
  int n;
  string s;
  cin >> n >> s;

  ll r = 0, g = 0, b = 0;
  for (auto c : s) {
    if (c == 'R')
      ++r;
    else if (c == 'G')
      ++g;
    else
      ++b;
  }
  // s[i],s[j],s[k]が異なるもの
  ll all = r * g * b;
  // 「s[i],s[j],s[k]が異なる」かつ「j-i=k-jである」
  ll sub = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (s[i] == s[j]) continue;
      // j-i=k-j => k = 2*j-i
      int k = j * 2 - i;
      if (k >= n || s[k] == s[i] || s[k] == s[j]) continue;
      ++sub;
    }
  }

  cout << all - sub << endl;
  return 0;
}