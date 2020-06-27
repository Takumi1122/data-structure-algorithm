#include <iostream>
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
const long long INF = 1LL << 60;

// 入力
int N;
long long W, weight[110],
    value[110];  // 品物の個数は 100 個なので少し余裕持たせてサイズ 110 に

// DPテーブル
long long dp[110][100100] = {0};

int main() {
  cin >> N >> W;
  for (int i = 0; i < N; ++i) cin >> weight[i] >> value[i];

  // DPループ
  for (int i = 0; i < N; ++i) {
    for (int sum_w = 0; sum_w <= W; ++sum_w) {
      // i 番目の品物を選ぶ場合
      if (sum_w - weight[i] >= 0) {
        chmax(dp[i + 1][sum_w], dp[i][sum_w - weight[i]] + value[i]);
      }

      // i 番目の品物を選ばない場合
      chmax(dp[i + 1][sum_w], dp[i][sum_w]);
    }
  }

  // 最適値の出力
  cout << dp[N][W] << endl;
}