#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 区間ごとに切り出す処理

/*
    参考リンク
    ABC 116 C - Grand Garden
      https://atcoder.jp/contests/abc116/tasks/abc116_c
*/

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i, n) cin >> h[i];

  int ans = 0;
  while (1) {
    if (*max_element(h.begin(), h.end()) == 0) break;

    int i = 0;
    while (i < n) {
      if (h[i] == 0)
        ++i;
      else {
        ++ans;
        while (i < n && h[i] > 0) {
          --h[i];
          ++i;
        }
      }
    }
  }

  cout << ans << endl;
  return 0;
}