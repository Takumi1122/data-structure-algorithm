#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 数え上げDP 禁止文字列 直近の3文字と新たに追加する文字

/*
    参考リンク
    ABC 122 D - We Like AGC
      https://atcoder.jp/contests/abc122/tasks/abc122_d
*/

const ll mod = 1e9 + 7;
void add(ll& a, ll b) { a = (a + b) % mod; }

// dp[i][a][b][c] : i番目まで見て、直近3文字がa, b, c
// 文字を示す添字は 0123 が TAGC に対応
ll dp[101][4][4][4];

// a, b, cが "AGC" だったらtrue
bool ng(int a, int b, int c) { return (a == 1 && b == 2 && c == 3); }

int main() {
  int n;
  cin >> n;

  // 初期状態の直近3文字はTTTであると見なして良い
  dp[0][0][0][0] = 1;

  rep(i, n) rep(a, 4) rep(b, 4) rep(c, 4) rep(d, 4) {
    // 文字列に文字dを足していく

    // 3文字NGパターン AGC, GAC, ACG
    if (ng(b, c, d) || ng(c, b, d) || ng(b, d, c)) continue;
    // 4文字NGパターン AXGC, AGXC
    if (ng(a, c, d) || ng(a, b, d)) continue;

    // NGパターンがなければ遷移先に足す
    add(dp[i + 1][b][c][d], dp[i][a][b][c]);
  }

  ll ans = 0;
  rep(a, 4) rep(b, 4) rep(c, 4) add(ans, dp[n][a][b][c]);
  cout << ans << endl;
  return 0;
}