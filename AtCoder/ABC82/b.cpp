#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 文字列の大小比較

/*
    参考リンク
    ABC 82 B - Two Anagrams
      https://atcoder.jp/contests/abc082/tasks/abc082_b
*/

int main() {
  string s, t;
  cin >> s >> t;

  sort(s.begin(), s.end());
  sort(t.begin(), t.end(), greater<char>());

  if (s < t) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}