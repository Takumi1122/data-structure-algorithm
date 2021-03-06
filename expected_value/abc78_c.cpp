#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 初めて表が出るまでに硬貨を投げた試行回数の期待値
// 表が出るまでの回数の期待値は確率の逆数という事実を覚えとく

/*
    参考リンク
    ABC 78 C - HSI
      https://atcoder.jp/contests/abc078/tasks/arc085_a
*/

int main() {
  int n, m;
  cin >> n >> m;
  int ans = ((n - m) * 100 + m * 1900) * (1 << m);
  cout << ans << endl;
  return 0;
}