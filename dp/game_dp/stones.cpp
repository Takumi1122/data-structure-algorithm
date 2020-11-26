#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    Educational DP Contest K - Stones
      https://atcoder.jp/contests/dp/tasks/dp_k
*/

// 石の個数が残りi個の局面が勝ちか負けかをbool値で表したもの
bool dp[110000];

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  for (int i = 1; i <= k; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i - a[j] >= 0) dp[i] |= !dp[i - a[j]];
    }
  }

  if (dp[k])
    cout << "First" << endl;
  else
    cout << "Second" << endl;
  return 0;
}