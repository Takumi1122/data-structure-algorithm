#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 全探索 O(n^3 * log(n))

/*
    参考リンク
    ABC 128 D - equeue
      https://atcoder.jp/contests/abc128/tasks/abc128_d
*/

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  rep(i, n) cin >> v[i];

  int ans = 0;
  for (int i = 0; i <= k; i++) {
    for (int j = 0; j <= k - i; j++) {
      if (i + j > n) continue;
      int d = k - i - j;
      int now = 0;
      vector<int> s;
      rep(x, i) {
        now += v[x];
        s.push_back(v[x]);
      }
      rep(x, j) {
        now += v[n - x - 1];
        s.push_back(v[n - x - 1]);
      }
      sort(s.begin(), s.end());
      rep(x, d) {
        if (x >= s.size()) break;
        if (s[x] >= 0) break;
        now -= s[x];
      }
      ans = max(ans, now);
    }
  }

  cout << ans << endl;
  return 0;
}