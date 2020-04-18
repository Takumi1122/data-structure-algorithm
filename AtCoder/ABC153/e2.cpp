#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, N;
  cin >> H >> N;

  vector<int> A(N);
  vector<int> B(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }

  // i 番目までの魔法からダメージの総和が j
  // になるように選んだときの魔法消費量の総和の最小値
  vector<vector<int>> dp(N + 1, vector<int>(H + 1, 100000000));

  dp[0][0] = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= H; j++) {
      if (j <= A[i]) {
        dp[i + 1][j] = min(dp[i][j], B[i]);
      } else {
        dp[i + 1][j] = min(dp[i][j], dp[i + 1][j - A[i]] + B[i]);
      }
    }
  }

  cout << dp[N][H] << endl;
}