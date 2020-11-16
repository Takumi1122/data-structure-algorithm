#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 183 C - Travel
      https://atcoder.jp/contests/abc183/tasks/abc183_c
*/

int main() {
  int n, k;
  cin >> n >> k;
  vector<vector<int> > dist(n, vector<int>(n));
  rep(i, n) rep(j, n) cin >> dist[i][j];

  vector<int> order;
  for (int i = 1; i < n; ++i) order.push_back(i);

  int ans = 0;
  do {
    int temp_dist = 0;
    temp_dist += dist[0][order[0]];
    rep(i, n - 2) temp_dist += dist[order[i]][order[i + 1]];
    temp_dist += dist[order.back()][0];

    if (temp_dist == k) ans++;
  } while (next_permutation(order.begin(), order.end()));

  cout << ans << endl;
}