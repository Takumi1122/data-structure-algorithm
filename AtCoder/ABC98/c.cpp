#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 左右からの累積和

/*
    参考リンク
    ABC 98 C - Attention
      https://atcoder.jp/contests/abc098/tasks/arc098_a
*/

int main() {
  int n;
  string s;
  cin >> n >> s;

  vector<int> lsum(n + 1);
  vector<int> rsum(n + 1);
  rep(i, n) {
    if (s[i] == 'W') lsum[i]++;
  }
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == 'E') rsum[n - i - 1]++;
  }
  rep(i, n) lsum[i + 1] += lsum[i];
  rep(i, n) rsum[i + 1] += rsum[i];

  int ans = 1e9;
  rep(i, n) {
    if (i == 0) {
      ans = min(ans, rsum[n - i - 2]);
      continue;
    }
    if (i == n - 1) {
      ans = min(ans, lsum[i - 1]);
      continue;
    }
    int cnt = lsum[i - 1] + rsum[n - i - 2];
    ans = min(ans, cnt);
  }

  cout << ans << endl;
  return 0;
}