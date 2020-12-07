#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC158 D - String Formation
      https://atcoder.jp/contests/abc158/tasks/abc158_d
*/

int main() {
  // sが末尾への追加
  string s;
  cin >> s;
  int q;
  cin >> q;
  // tが先頭への追加
  string t;

  rep(qi, q) {
    int ty;
    cin >> ty;
    if (ty == 1) {
      swap(s, t);
    } else {
      int f;
      char c;
      cin >> f >> c;
      if (f == 1) {
        t += c;
      } else {
        s += c;
      }
    }
  }

  reverse(t.begin(), t.end());
  t += s;
  cout << t << endl;
  return 0;
}