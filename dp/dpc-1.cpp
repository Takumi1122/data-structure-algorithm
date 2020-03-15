#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

// 入力
int N;
long long a[100010][3];  // a[i], b[i], c[i] をそれぞれまとめて a[i][0],
                         // a[i][1], a[i][2] にしてしまう

// DP テーブル
long long dp[100010][3];

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < 3; ++j) cin >> a[i][j];

  // 初期化は既に 0 に初期化される
  // 初期条件も既に 0 で OK

  // ループ
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        if (j == k) continue;
        chmax(dp[i + 1][k], dp[i][j] + a[i][k]);
      }
    }
  }

  // 答え
  long long res = 0;
  for (int j = 0; j < 3; ++j) chmax(res, dp[N][j]);
  cout << res << endl;
}