#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 素因数分解したときの指数の和+1

/*
    参考リンク
    ARC 115 C - ℕ Coloring
      https://atcoder.jp/contests/arc115/tasks/arc115_c
*/

vector<pair<ll, ll>> prime_factorize(ll n) {
  vector<pair<ll, ll>> res;
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

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    auto pf = prime_factorize(i);
    int ans = 1;
    for (auto p : pf) ans += p.second;
    cout << ans << endl;
  }
  return 0;
}