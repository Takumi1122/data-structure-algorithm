#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 等差数列 公差1 約数列挙 偶奇

/*
    [A,A+1,...B] の総和 = (B+A)(B-A+1)/2
    よって, (B+A)(B-A+1) = 2n
    B+A, B-A+1 はどちらも整数なので,どちらも 2n の約数

    B+A = x, B-A+1 = y <=> A = (x-y+1)/2, B = (x+y-1)/2

    xとyの偶奇が一致するとき整数解は存在しない
*/

/*
    参考リンク
    ABC 190 D - Staircase Sequences
      https://atcoder.jp/contests/abc190/tasks/abc190_d
*/

vector<ll> enum_divisors(ll n) {
  vector<ll> res;
  for (ll i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      res.push_back(i);
      // 重複しないならば i の相方である N/i も push
      if (n / i != i) res.push_back(n / i);
    }
  }
  // 小さい順に並び替える
  sort(res.begin(), res.end());
  return res;
}

int main() {
  ll n;
  cin >> n;

  auto e = enum_divisors(2 * n);
  ll ans = 0;
  for (auto ei : e) {
    ll a = 2 * n / ei;
    if (ei % 2 == 0 && a % 2 == 1) ans++;
    if (ei % 2 == 1 && a % 2 == 0) ans++;
  }

  cout << ans << endl;
  return 0;
}