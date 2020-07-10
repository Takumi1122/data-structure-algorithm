#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MOD = 1000000007;

// res[i][c] := i 文字目以降で最初に文字 c が登場する index (存在しないときは n)
vector<vector<int> > calcNext(const string &S) {
  int n = (int)S.size();
  vector<vector<int> > res(n + 1, vector<int>(26, n));
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < 26; ++j) res[i][j] = res[i + 1][j];
    res[i][S[i] - 'a'] = i;
  }
  return res;
}

void add(ll &a, ll b) {
  a += b;
  if (a >= MOD) a -= MOD;
}

int main() {
  string s;
  cin >> s;
  int n = (int)s.size();
  string t = s;
  reverse(t.begin(), t.end());

  auto ns = calcNext(s);
  auto nt = calcNext(t);
  vector<vector<ll> > dp(n + 1, vector<ll>(n + 1, 0));
  dp[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < 26; ++k) {
        int ni = ns[i][k];
        int nj = nt[j][k];
        if (ni + nj + 2 > n) continue;
        add(dp[ni + 1][nj + 1], dp[i][j]);
      }
    }
  }

  ll res = 0;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; i + j <= n; ++j) {
      int num = 1;
      for (int k = 0; k < 26; ++k)
        if (ns[i][k] + 1 + j <= n) ++num;
      res = (res + dp[i][j] * num % MOD) % MOD;
    }
  }
  cout << res - 1 << endl;
}