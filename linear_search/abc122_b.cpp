#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 連続する部分文字列 n(n+1)/2 を全探索

/*
    参考リンク
    ABC 122 B - GeT AC
      https://atcoder.jp/contests/abc122/tasks/abc122_b
*/

int main() {
  string s;
  cin >> s;

  int n = s.size();
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      bool ok = true;
      for (int k = i; k < j; ++k) {
        if (s[k] != 'A' && s[k] != 'G' && s[k] != 'C' && s[k] != 'T')
          ok = false;
      }
      if (ok) ans = max(ans, j - i);
    }
  }

  cout << ans << endl;
  return 0;
}