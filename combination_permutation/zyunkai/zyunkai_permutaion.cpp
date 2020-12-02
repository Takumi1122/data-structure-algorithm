#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 100000000;

int main() {
  int n;
  cin >> n;
  vector<vector<int> > dist(n, vector<int>(n));
  rep(i, n) rep(j, n) cin >> dist[i][j];

  vector<int> order(n);
  rep(i, n) order[i] = i;

  int ans = INF;
  do {
    int temp_dist = 0;
    for (int i = 1; i < n; ++i) {
      temp_dist += dist[order[i - 1]][order[i]];
    }
    ans = min(ans, temp_dist);
  } while (next_permutation(order.begin(), order.end()));

  cout << ans << endl;
  return 0;
}
