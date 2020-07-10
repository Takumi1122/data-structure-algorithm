#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// chmin
template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

// res[i][c] := i 文字目以降で最初に文字 c が登場する index (存在しないときは n)
vector<vector<int> > calcNext(const string &S) {
  int n = (int)S.size();
  vector<vector<int> > res(n + 2, vector<int>(26, n + 1));
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < 26; ++j) res[i][j] = res[i + 1][j];
    res[i][S[i] - 'a'] = i;
  }
  return res;
}

string solve(const string &S) {
  int n = (int)S.size();

  // 前処理配列
  auto next = calcNext(S);

  // DP
  vector<int> dp(n + 1, 1 << 29);  // DP テーブル
  vector<char> recon(n + 1, 'a');  // 復元用テーブル
  dp[n] = 1;
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < 26; ++j) {
      // 次の文字がないとき
      if (next[i][j] == n + 1) {
        if (dp[i] > 1) {
          dp[i] = 1;
          recon[i] = 'a' + j;
        }
      }
      // 次の文字があるとき
      else if (chmin(dp[i], dp[next[i][j] + 1] + 1)) {
        recon[i] = 'a' + j;
      }
    }
  }

  // 復元
  string res = "";
  int index = 0;
  while (index <= n) {
    res += recon[index];
    index = next[index][recon[index] - 'a'] + 1;
  }
  return res;
}

int main() {
  string s;
  cin >> s;
  cout << solve(s) << endl;
}