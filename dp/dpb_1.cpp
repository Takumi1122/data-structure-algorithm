#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

const long long INF = 1LL << 60;

// 入力
int N;
long long h[110000];

// DP テーブル
long long dp[110000];

int main() {
  int N, K;
  cin >> N >> K;
  for (int i = 0; i < N; ++i) cin >> h[i];

  // 初期化 (最小化問題なので INF に初期化)
  for (int i = 0; i < 110000; ++i) dp[i] = INF;

  // 初期条件
  dp[0] = 0;

  // ループ
  for (int i = 0; i < N; ++i) {
    for (int j = 1; j <= K; ++j) {
      chmin(dp[i + j], dp[i] + abs(h[i] - h[i + j]));
    }
  }

  // 答え
  cout << dp[N - 1] << endl;
}