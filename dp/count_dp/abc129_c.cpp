#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 129 C - Typical Stairs
      https://atcoder.jp/contests/abc129/tasks/abc129_c
*/

const int mod = 1e9 + 7;
ll dp[100010];

int main() {
  int n, m;
  cin >> n >> m;
  set<int> a;
  rep(i, m) {
    int am;
    cin >> am;
    a.insert(am);
  }

  dp[0] = 1;
  rep(i, n) {
    if (!a.count(i + 1)) {
      dp[i + 1] += dp[i];
      dp[i + 1] %= mod;
    }
    if (!a.count(i + 2)) {
      dp[i + 2] += dp[i];
      dp[i + 2] %= mod;
    }
  }

  cout << dp[n] << endl;
  return 0;
}