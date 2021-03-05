#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 重さが4種類のナップサック問題
// 全探索

/*
    参考リンク
    ABC 60 D - Simple Knapsack
      https://atcoder.jp/contests/abc060/tasks/arc073_b
*/

int main() {
  ll n, w;
  cin >> n >> w;

  vector<vector<ll>> st(4);
  ll w1;
  rep(i, n) {
    ll wi, vi;
    cin >> wi >> vi;
    if (i == 0) w1 = wi;
    st[wi - w1].push_back(vi);
  }

  rep(i, 4) {
    sort(st[i].begin(), st[i].end());
    st[i].push_back(0);
    reverse(st[i].begin(), st[i].end());
    for (int j = 1; j < st[i].size(); j++) {
      st[i][j] += st[i][j - 1];
    }
  }

  ll ans = 0;
  rep(i, st[0].size()) rep(j, st[1].size()) rep(k, st[2].size())
      rep(l, st[3].size()) {
    ll sum = w1 * i + (w1 + 1) * j + (w1 + 2) * k + (w1 + 3) * l;
    if (sum <= w) ans = max(ans, st[0][i] + st[1][j] + st[2][k] + st[3][l]);
  }

  cout << ans << endl;
  return 0;
}