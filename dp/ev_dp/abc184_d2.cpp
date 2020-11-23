#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

// 期待値DP

/*
    参考リンク
    ABC 184 D - increment of coins
      https://atcoder.jp/contests/abc184/tasks/abc184_d
*/

const int X = 100;
double dp[X + 1][X + 1][X + 1];

double f(int a, int b, int c) {
  if (dp[a][b][c]) return dp[a][b][c];
  if (a == 100 || b == 100 || c == 100) return 0;
  double ans = 0;
  ans += f(a + 1, b, c) * a;
  ans += f(a, b + 1, c) * b;
  ans += f(a, b, c + 1) * c;
  ans = ans / (a + b + c) + 1;
  dp[a][b][c] = ans;
  return ans;
}

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  printf("%.10f\n", f(a, b, c));
}