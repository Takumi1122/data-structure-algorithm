#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 最長増加部分列
// 計算量 o(nlog(n))

/*
    参考リンク
    AIZU ONLINE JUDGE
      https://onlinejudge.u-aizu.ac.jp/problems/DPL_1_D

    LIS でも大活躍！ DP の配列使いまわしテクニックを特集
      https://qiita.com/drken/items/68b8503ad4ffb469624c
*/

const ll INF = 1LL << 60;

// 最長増加部分列の長さを求める
int LIS(const vector<ll> &a) {
  int n = (int)a.size();
  vector<ll> dp(n, INF);

  rep(i, n) {
    // dp[k] >= a[i] となる最小のイテレータを見つける
    auto it = lower_bound(dp.begin(), dp.end(), a[i]);

    // そこを a[i] で書き換える
    *it = a[i];
  }

  // dp[k] < INF となる最大の k に対して k+1 が答え
  // それは dp[k] >= INF となる最小の k に一致する
  return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  cout << LIS(a) << endl;
}