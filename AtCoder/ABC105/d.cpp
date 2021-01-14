#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 配列の連続する区間 = 累積和をとった配列上の2点
// s[right] - s[left]がmの倍数 <=> s[right]とs[left]をmで割ったあまりが等しい
// 「条件を満たす区間の個数を数え上げよ」 = しゃくとり法や累積和が候補

/*
    参考リンク
    ABC 105 D - Candy Distribution
      https://atcoder.jp/contests/abc105/tasks/abc105_d
*/

int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  map<ll, ll> nums;
  ll sum = 0;
  nums[sum]++;
  rep(i, n) {
    sum += a[i];
    nums[sum % m]++;
  }

  ll ans = 0;
  for (auto num : nums) {
    ans += num.second * (num.second - 1) / 2;
  }

  cout << ans << endl;
  return 0;
}