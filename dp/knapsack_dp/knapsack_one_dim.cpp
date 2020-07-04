#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

template <class T>
void chmax(T &a, T b) {
  if (a < b) a = b;
}

int main() {
  int n, W;
  cin >> n >> W;
  vector<int> weight(n), value(n);
  rep(i, n) cin >> weight[i] >> value[i];

  vector<long long> dp(W + 1, 0);
  for (int i = 0; i < n; ++i) {
    for (int w = W; w >= 0; --w) {
      if (w - weight[i] >= 0) {
        chmax(dp[w], dp[w - weight[i]] + value[i]);
      }
    }
  }
  cout << dp[W] << endl;
}