#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    Sの部分文字列(空文字含む)として考えられるものの個数 O(n)
    ※ 連続しない部分文字列も含む
    ※ 連続する部分文字列のみの場合は、Suffix Array + LCP
*/

const int MOD = 1000000007;

// res[i][c] := i 文字目以降で最初に文字 c が登場する index (存在しないときは n)
// 0-index
vector<vector<int> > calcNext(const string &S) {
  int n = (int)S.size();
  vector<vector<int> > res(n + 1, vector<int>(26, n));
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < 26; ++j) res[i][j] = res[i + 1][j];
    res[i][S[i] - 'a'] = i;
  }
  return res;
}

// mod 1000000007 の世界で a += b する関数
void add(ll &a, ll b) {
  a += b;
  if (a >= MOD) a -= MOD;
}

int main() {
  // 入力
  string s;
  cin >> s;
  int n = (int)s.size();

  // 前処理配列
  vector<vector<int> > next = calcNext(s);

  // DP
  /*
      文字列Sにおいて、i−1番目の文字(0-inedexed)は必ず使うものとして
      Sのうち0番目から i−1番目までの部分から得られる部分文字列の個数
  */
  vector<ll> dp(n + 1, 0);
  dp[0] = 1;  // 初期化、空文字列 "" に対応
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 26; ++j) {
      if (next[i][j] >= n) continue;  // 次の文字 j がもうない場合はスルー
      add(dp[next[i][j] + 1], dp[i]);
    }
  }

  // 集計
  ll res = 0;
  for (int i = 0; i <= n; ++i) add(res, dp[i]);

  cout << res << endl;
}