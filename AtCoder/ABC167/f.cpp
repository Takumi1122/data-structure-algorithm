#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 括弧列
// (: +1, ): -1 に変換
// 折れ線で考える

/*
    参考リンク
    ABC 167 F - Bracket Sequencing
      https://atcoder.jp/contests/abc167/tasks/abc167_f
*/

bool check(vector<P> s) {
  int h = 0;
  for (P p : s) {
    int b = h + p.first;
    if (b < 0) return false;
    h += p.second;
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  // ls: 増減プラス, rs: 増減マイナス
  vector<P> ls, rs;
  int total = 0;
  rep(i, n) {
    string s;
    cin >> s;
    // h: 最終的な増減, b: 最下点
    int h = 0, b = 0;
    for (char c : s) {
      if (c == '(')
        ++h;
      else
        --h;
      b = min(b, h);
    }
    if (h > 0)
      ls.emplace_back(b, h);
    else
      rs.emplace_back(b - h, -h);
    total += h;
  }

  sort(ls.rbegin(), ls.rend());
  sort(rs.rbegin(), rs.rend());

  if (check(ls) && check(rs) && total == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}