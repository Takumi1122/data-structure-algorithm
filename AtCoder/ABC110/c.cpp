#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 2つのアルファベットを選んで入れ替える
// 同じ文字が異なる文字に変換されない
// 異なる文字が同じ文字に変換されない

/*
    参考リンク
    ABC 110 C - String Transformation
      https://atcoder.jp/contests/abc110/tasks/abc110_c
*/

int main() {
  string s, t;
  cin >> s >> t;

  bool ok = true;
  map<char, char> ma, ima;
  rep(i, s.size()) {
    char c1 = s[i];
    char c2 = t[i];
    if (ma.count(c1))
      if (ma[c1] != c2) ok = false;
    if (ima.count(c2))
      if (ima[c2] != c1) ok = false;
    ma[c1] = c2;
    ima[c2] = c1;
  }

  if (ok)
    puts("Yes");
  else
    puts("No");
}