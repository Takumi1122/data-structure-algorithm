#include <bits/stdc++.h>
using namespace std;
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

using pll = pair<long long, long long>;
int main() {
  int N;
  cin >> N;
  vector<pll> A(N);
  for (int i = 0; i < N; ++i) cin >> A[i].first, A[i].second = i;
  sort(A.begin(), A.end(), greater<pll>());

  vector<vector<long long>> dp(N + 1, vector<long long>(N + 1, 0));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; i + j < N; ++j) {
      // left
      chmax(dp[i + 1][j], dp[i][j] + A[i + j].first * (A[i + j].second - i));

      // right
      chmax(dp[i][j + 1],
            dp[i][j] + A[i + j].first * ((N - 1 - j) - A[i + j].second));
    }
  }
  long long res = 0;
  for (int i = 0; i <= N; ++i) chmax(res, dp[i][N - i]);
  cout << res << endl;
}