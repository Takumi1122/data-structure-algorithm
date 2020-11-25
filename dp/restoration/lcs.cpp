#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    Educational DP Contest F - LCS
      https://atcoder.jp/contests/dp/tasks/dp_f
*/

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

const ll INF = 1LL << 60;
int dp[3100][3100];

int main() {
  string s, t;
  cin >> s >> t;

  rep(i, s.size()) rep(j, t.size()) {
    if (s[i] == t[j]) chmax(dp[i + 1][j + 1], dp[i][j] + 1);
    chmax(dp[i + 1][j + 1], dp[i + 1][j]);
    chmax(dp[i + 1][j + 1], dp[i][j + 1]);
  }

  string ans = "";
  int i = (int)s.size(), j = (int)t.size();
  while (i > 0 && j > 0) {
    // (i-1, j) -> (i, j) と更新されていた場合
    if (dp[i][j] == dp[i - 1][j]) {
      --i;
    }

    // (i, j-1) -> (i, j) と更新されていた場合
    else if (dp[i][j] == dp[i][j - 1]) {
      --j;
    }

    // (i-1, j-1) -> (i, j) と更新されていた場合
    else {
      ans = s[i - 1] + ans;
      --i, --j;
    }
  }
  cout << ans << endl;
}