#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// a1 + a2 + ... + an = m
// d = gcd(a1,a2,...,an)
// m = k*d dはmの約数 (kは整数)
// n*d <= m を満たす

/*
    参考リンク
    ABC 112 D - Partition
      https://atcoder.jp/contests/abc112/tasks/abc112_d
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
  ll n, m;
  cin >> n >> m;
  vector<ll> div = enum_divisors(m);

  // Mの約数dであって,d * N <= Mとなる最大のdを求める
  ll ans = 1;
  for (auto d : div) {
    if (d * n <= m) ans = max(ans, d);
  }

  cout << ans << endl;
  return 0;
}