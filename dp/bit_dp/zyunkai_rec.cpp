#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// O(n^2 * 2^n) 巡回セールスマン問題　bitDP

const int INF = 100000000;  // 十分大きな値

/* 入力 */
int n;
int dist[21][21];

/* メモ再帰 */
int dp[(1 << 20) + 1][21];  // dpテーブルは余裕をもったサイズにする

int rec(int bit, int v) {
  // すでに探索済みだったらリターン
  if (dp[bit][v] != -1) return dp[bit][v];

  // 初期値
  if (bit == (1 << v)) {
    return dp[bit][v] = 0;
  }

  // 答えを格納する変数
  int res = INF;

  // bit の v を除いたもの
  int prev_bit = bit & ~(1 << v);

  // v の手前のノードとして u を全探索
  rep(u, n) {
    if (!(prev_bit & (1 << u))) continue;  // u が prev_bit になかったらダメ

    // 再帰的に探索
    if (res > rec(prev_bit, u) + dist[u][v]) {
      res = rec(prev_bit, u) + dist[u][v];
    }
  }

  return dp[bit][v] = res;  // メモしながらリターン
}

int main() {
  // 入力
  cin >> n;
  rep(i, n) rep(j, n) cin >> dist[i][j];

  // テーブルを全部 -1 にしておく (-1 でなかったところは探索済)
  for (int bit = 0; bit < (1 << n); ++bit) rep(v, n) dp[bit][v] = -1;

  // 探索
  int res = INF;
  rep(v, n) {
    if (res > rec((1 << n) - 1, v)) {
      res = rec((1 << n) - 1, v);
    }
  }
  cout << res << endl;
}