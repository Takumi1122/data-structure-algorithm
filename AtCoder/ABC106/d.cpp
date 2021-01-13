#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 2次元累積和 O(n^2)
// 完全に含まれる区間の個数

/*
    参考リンク
    ABC 106 D - AtCoder Express 2
      https://atcoder.jp/contests/abc106/tasks/abc106_d
*/

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> sum(n + 1, vector<int>(n + 1));
  rep(i, m) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    sum[l][r]++;
  }

  rep(j, n) for (int i = n - 1; i >= 0; i--) sum[i][j] += sum[i + 1][j];
  rep(i, n) rep(j, n) sum[i][j + 1] += sum[i][j];

  rep(i, q) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    cout << sum[l][r] << endl;
  }
  return 0;
}