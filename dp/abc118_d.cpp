#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const string MINUSINF = "-";

// 文字列の大小関係は辞書順
// 文字列を値にもつDP

/*
    参考リンク
    ABC 118 D - Match Matching
      https://atcoder.jp/contests/abc118/tasks/abc118_d
*/

// 文字列を数値で表しているときの大小比較
void chmax(string &a, string b) {
  if (a == MINUSINF)
    a = b;
  else if (a.size() < b.size())
    a = b;
  else if (a.size() == b.size()) {
    if (a < b) a = b;
  }
}

ll match[10] = {2, 5, 5, 4, 5, 6, 3, 7, 6};
// dp[i]: マッチ棒をi本使って作れる数値の最大値
string dp[11000];

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  rep(i, m) cin >> a[i];

  rep(i, 11000) dp[i] = MINUSINF;
  dp[0] = "";

  for (int i = 0; i <= n; ++i) {
    if (dp[i] == MINUSINF) continue;
    for (auto j : a) chmax(dp[i + match[j - 1]], dp[i] + (char)('0' + j));
  }

  cout << dp[n] << endl;
  return 0;
}