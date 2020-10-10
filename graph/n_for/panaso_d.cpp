#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    先頭から文字を追加していくが
    「追加するのに使えるのは'a'～今まで使われた文字の次の文字」
*/

/*
    参考リンク
    パナソニックプログラミングコンテスト2020 D - String Equivalence
      https://atcoder.jp/contests/panasonic2020/tasks/panasonic2020_d
*/

int n;
void dfs(string s, char mx) {
  if (s.size() == n) {
    cout << s << endl;
    return;
  }
  for (char c = 'a'; c <= mx + 1; c++) {
    string t = s;
    t += c;
    dfs(t, max(mx, c));
  }
}

int main() {
  cin >> n;
  dfs("", 'a' - 1);
  return 0;
}