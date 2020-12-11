#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 約数列挙 O(√n)

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
  const auto &res = enum_divisors(n);
  rep(i, res.size()) cout << res[i] << " ";
  cout << endl;
}