#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// BFS

/*
    参考リンク
    ABC 99 C - Strange Bank
      https://atcoder.jp/contests/abc099/tasks/abc099_c
*/

const int MAX_N = 110000;
int dp[MAX_N];

int main() {
  int n;
  cin >> n;

  rep(i, MAX_N) dp[i] = -1;
  dp[0] = 0;
  queue<int> que;
  que.push(0);

  // BFS
  while (!que.empty()) {
    int v = que.front();
    que.pop();

    for (int pow6 = 1; v + pow6 <= n; pow6 *= 6) {
      if (dp[v + pow6] == -1) {
        dp[v + pow6] = dp[v] + 1;
        que.push(v + pow6);
      }
    }
    for (int pow9 = 1; v + pow9 <= n; pow9 *= 9) {
      if (dp[v + pow9] == -1) {
        dp[v + pow9] = dp[v] + 1;
        que.push(v + pow9);
      }
    }
  }

  cout << dp[n] << endl;
  return 0;
}