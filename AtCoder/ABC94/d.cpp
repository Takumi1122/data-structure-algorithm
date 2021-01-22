#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 二項係数 最大値
// nCrについて r が n/2 に近いほど大きい パスカルの三角形から分かる

/*
    参考リンク
    ABC 94 D - Binomial Coefficients
      https://atcoder.jp/contests/abc094/tasks/arc095_b
*/

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  sort(a.begin(), a.end());
  int mx = a[n - 1];

  int ai = 0;
  int ab = 0;
  rep(i, n) {
    int abi = min(mx - a[i], a[i]);
    if (abi > ab) {
      ai = a[i];
      ab = abi;
    }
  }

  cout << mx << " " << ai << endl;
  return 0;
}