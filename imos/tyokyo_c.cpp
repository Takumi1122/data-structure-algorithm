#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    東京海上日動 プログラミングコンテスト2020 C - Lamps
      https://atcoder.jp/contests/tokiomarine2020/tasks/tokiomarine2020_c
*/

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  rep(ki, k) {
    vector<int> b(n + 1);
    rep(i, n) {
      int l = max(0, i - a[i]);
      int r = min(i + a[i] + 1, n);
      b[l]++;
      b[r]--;
    }
    rep(i, n) b[i + 1] += b[i];
    b.pop_back();
    if (a == b) break;
    a = b;
  }
  rep(i, n) cout << a[i] << endl;
  return 0;
}