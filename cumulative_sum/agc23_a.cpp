#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

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

  // 集計処理
  ll res = 0;
  for (auto it : nums) {
    ll num = it.second;  // it.first が it.second 個ある
    res += num * (num - 1) / 2;
  }
  cout << res << endl;
}