#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 配列の連続する区間 = 累積和をとった配列上の2点
// 「条件を満たす区間の個数を数え上げよ」 = しゃくとり法や累積和が候補

/*
    参考リンク
    AGC 23 A - Zero-Sum Ranges
      https://atcoder.jp/contests/agc023/tasks/agc023_a
*/

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  // 累積和と連想配列
  vector<ll> s(n + 1, 0);
  map<ll, ll> nums;
  rep(i, n) s[i + 1] = s[i] + a[i];
  rep(i, n + 1) nums[s[i]]++;

  ll ans = 0;
  for (auto it : nums) {
    ll num = it.second;
    ans += num * (num - 1) / 2;
  }

  cout << ans << endl;
  return 0;
}