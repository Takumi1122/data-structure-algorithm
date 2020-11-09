#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 累積max

/*
    参考リンク
    ABC 124 B - Great Ocean View
      https://atcoder.jp/contests/abc124/tasks/abc124_b
*/

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i, n) cin >> h[i];

  int ans = 0;
  int max_h = 0;
  rep(i, n) {
    if (h[i] >= max_h) {
      ans++;
      max_h = h[i];
    }
  }

  cout << ans << endl;
  return 0;
}