#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    Educational DP Contest A - Frog 1
      https://atcoder.jp/contests/dp/tasks/dp_a
*/

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const ll INF = 1LL << 60;
ll h[100010];
ll dp[100010];

ll rec(int i) {
  if (dp[i] < INF) return dp[i];
  if (i == 0) return 0;

  ll res = INF;
  chmin(res, rec(i - 1) + abs(h[i] - h[i - 1]));
  if (i > 1) chmin(res, rec(i - 2) + abs(h[i] - h[i - 2]));

  return dp[i] = res;
}

int main() {
  int n;
  cin >> n;
  rep(i, n) cin >> h[i];
  rep(i, 100010) dp[i] = INF;

  cout << rec(n - 1) << endl;
  return 0;
}