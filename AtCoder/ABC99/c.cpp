#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// メモ化再帰
// DPの計算量は通常 O(ノード数+遷移数)
// 今回の遷移数 O(n*log(n))

/*
    参考リンク
    ABC 99 C - Strange Bank
      https://atcoder.jp/contests/abc099/tasks/abc099_c
*/

const int MAX_N = 110000;
int memo[MAX_N];

int rec(int n) {
  if (n == 0) return 0;
  if (memo[n] != -1) return memo[n];

  int res = n;

  // 1,6,6^2,...,を試す (nを超えない範囲で)
  for (int pow6 = 1; pow6 <= n; pow6 *= 6) res = min(res, rec(n - pow6) + 1);

  // 1,9,9^2,...,を試す (nを超えない範囲で)
  for (int pow9 = 1; pow9 <= n; pow9 *= 9) res = min(res, rec(n - pow9) + 1);

  return memo[n] = res;
}

int main() {
  int n;
  cin >> n;

  rep(i, MAX_N) memo[i] = -1;

  cout << rec(n) << endl;
  return 0;
}