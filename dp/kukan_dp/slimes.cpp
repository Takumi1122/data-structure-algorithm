#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 区間の除去・圧縮・合体がある

/*
    参考リンク
    Educational DP Contest N - Slimes
      https://atcoder.jp/contests/dp/tasks/dp_n
*/

const ll INF = 1LL << 60;

ll a[409];
ll dp[409][409];

ll rec(int l, int r) {
  if (l == r) return 0;
  if (dp[l][r] != 0) return dp[l][r];

  ll res = INF;
  for (int i = l; i < r; i++) res = min(res, rec(l, i) + rec(i + 1, r));

  res += a[r];
  if (l > 0) res -= a[l - 1];
  return dp[l][r] = res;
}

int main() {
  int n;
  cin >> n;
  rep(i, n) {
    cin >> a[i];
    if (i) a[i] += a[i - 1];
  }

  cout << rec(0, n - 1) << endl;

  return 0;
}