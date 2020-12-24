#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 上位の桁（今回はビット）から決めていく
// 「Xが上限Kよりも小さいことが確定しているか？」をフラグとして持った状態を考える

// K以下のxについてのf(x)の最大値を求めることが要求されている時点で,桁DPがうまくいくことが多い

/*
    参考リンク
    ABC 117 D - XXOR
      https://atcoder.jp/contests/abc117/tasks/abc117_d
*/

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

ll dp[100][2];

int main() {
  int n;
  ll k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  rep(i, 100) dp[i][0] = dp[i][1] = -1;
  dp[45][0] = 0;

  for (int d = 44; d >= 0; --d) {
    ll mask = 1LL << d;
    int num = 0;
    // dビット目が1であるa[i]の数
    rep(i, n) if (a[i] & mask) num++;

    if (dp[d + 1][1] >= 0)
      chmax(dp[d][1], dp[d + 1][1] + mask * max(num, n - num));
    if (dp[d + 1][0] >= 0) {
      if (k & (1LL << d)) {
        chmax(dp[d][1], dp[d + 1][0] + mask * num);
        chmax(dp[d][0], dp[d + 1][0] + mask * (n - num));
      } else {
        chmax(dp[d][0], dp[d + 1][0] + mask * num);
      }
    }
  }

  cout << max(dp[0][0], dp[0][1]) << endl;
  return 0;
}