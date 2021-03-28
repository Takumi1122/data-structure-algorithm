#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// rotate(first, middle, last)
// middleの要素が先頭、middle-1の要素が末尾となるように、[first,last)の要素の並びを回転させる

/*
    参考リンク
    ABC 197 A - Rotate
      https://atcoder.jp/contests/abc197/tasks/abc197_a
*/

int main() {
  string s;
  cin >> s;
  rotate(s.begin(), s.begin() + 1, s.end());
  cout << s << endl;
  return 0;
}