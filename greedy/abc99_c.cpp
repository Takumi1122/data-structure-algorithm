#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 全探索 + Greedy

/*
    参考リンク
    ABC 99 C - Strange Bank
      https://atcoder.jp/contests/abc099/tasks/abc099_c
*/

// a進法でnの桁和
int func(int n, int a) {
  int res = 0;
  while (n > 0) {
    res += n % a;
    n /= a;
  }
  return res;
}

int main() {
  int n;
  cin >> n;

  int ans = n;
  for (int i = 0; i <= n; ++i) {
    int tmp = func(i, 6) + func(n - i, 9);
    ans = min(ans, tmp);
  }

  cout << ans << endl;
  return 0;
}