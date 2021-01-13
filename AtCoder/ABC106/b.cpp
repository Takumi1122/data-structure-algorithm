#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

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
  int n;
  cin >> n;

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (i % 2 == 0) continue;
    auto a = enum_divisors(i);
    if (a.size() == 8) ans++;
  }

  cout << ans << endl;
  return 0;
}