#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 約数の個数と素因数分解
// n!の約数

/*
    参考リンク
    ABC 114 D - 756
      https://atcoder.jp/contests/abc114/tasks/abc114_d
*/

vector<pair<ll, ll> > prime_factorize(ll n) {
  vector<pair<ll, ll> > res;
  for (ll a = 2; a * a <= n; ++a) {
    if (n % a != 0) continue;
    ll ex = 0;  // 指数

    // 割れる限り割り続ける
    while (n % a == 0) {
      ++ex;
      n /= a;
    }

    // その結果を push
    res.push_back({a, ex});
  }

  // 最後に残った数について
  if (n != 1) res.push_back({n, 1});
  return res;
}

int dp[101][76];

int main() {
  int n;
  cin >> n;
  map<int, int> mp;
  for (int i = 2; i <= n; i++) {
    auto pf = prime_factorize(i);
    for (auto p : pf) mp[p.first] += p.second;
  }

  vector<int> nums;
  for (auto p : mp) nums.push_back(p.second);

  int len = nums.size();
  vector<int> div75 = {1, 3, 5, 15, 25, 75};
  dp[0][1] = 1;

  for (int i = 0; i < len; i++) {
    for (auto d1 : div75) {
      for (auto d2 : div75) {
        if (d1 * d2 <= 75 && nums[i] + 1 >= d2) {
          dp[i + 1][d1 * d2] += dp[i][d1];
        }
      }
    }
  }

  cout << dp[len][75] << endl;
  return 0;
}