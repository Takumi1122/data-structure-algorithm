#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 個数制限なしナップサック 最小化

/*
    参考リンク
    ABC 99 C - Strange Bank
      https://atcoder.jp/contests/abc099/tasks/abc099_c
*/

const int MAX_W = 110000;
int dp[MAX_W];

int main() {
  int w;
  cin >> w;

  // 品物を列挙(価値はすべて1)
  vector<int> weight;
  for (int i = 1; i <= w; i *= 6) weight.push_back(i);
  for (int i = 9; i <= w; i *= 9) weight.push_back(i);
  int n = (int)weight.size();

  rep(i, MAX_W) dp[i] = 1 << 29;
  dp[0] = 0;

  rep(i, n) {
    for (int j = weight[i]; j <= w; ++j) {
      dp[j] = min(dp[j], dp[j - weight[i]] + 1);
    }
  }

  cout << dp[w] << endl;
  return 0;
}