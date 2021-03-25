#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// ハミング距離とは、等しい文字数を持つ二つの文字列の中で対応する位置にある異なった文字の個数
// ハミング距離が偶数なら正答数が等しくなる
// 1（もしくは0）の個数の偶奇が重要

/*
    参考リンク
    ARC 115 A - Two Choices
      https://atcoder.jp/contests/arc115/tasks/arc115_a
*/

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  rep(i, n) cin >> s[i];

  vector<int> zero;
  rep(i, n) {
    int cnt = 0;
    rep(j, s[i].size()) {
      if (s[i][j] == '0') cnt++;
    }
    zero.push_back(cnt);
  }

  ll odd = 0;
  ll even = 0;
  rep(i, n) {
    if (zero[i] % 2 == 0) {
      even++;
    } else {
      odd++;
    }
  }

  cout << odd * even << endl;
  return 0;
}