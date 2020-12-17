#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 'C'が右隣にあるような'A'の個数
// "TTACTTTA|C"のような「右端の'A'の右隣に'C'がある」というような'A'を除外する

/*
    参考リンク
    ABC 122 C - GeT AC
      https://atcoder.jp/contests/abc122/tasks/abc122_c
*/

int main() {
  int n, q;
  string s;
  cin >> n >> q >> s;

  vector<int> sum(n + 1, 0);
  rep(i, n - 1) {
    if (s[i] == 'A' && s[i + 1] == 'C') {
      sum[i + 1]++;
    }
  }
  rep(i, n) sum[i + 1] += sum[i];

  rep(i, q) {
    int l, r;
    cin >> l >> r;
    cout << sum[r - 1] - sum[l - 1] << endl;
  }
  return 0;
}