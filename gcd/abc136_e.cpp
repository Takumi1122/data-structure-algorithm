#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// Ai++ Aj-- => 合計は変わらない
// 解の候補は合計の約数

/*
    参考リンク
    ABC 136 E - Max GCD
      https://atcoder.jp/contests/abc136/tasks/abc136_e
*/

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  ll sum = 0;
  rep(i, n) sum += a[i];
  // sumの約数列挙 O(√sum)
  set<ll> candidates;
  for (int i = 1; i * i <= sum; i++) {
    if (sum % i == 0) {
      candidates.insert(i);
      candidates.insert(sum / i);
    }
  }

  ll ans = 1;
  for (ll x : candidates) {
    ll need;
    {  // calc need
      vector<ll> r(n);
      rep(i, n) r[i] = a[i] % x;
      sort(r.begin(), r.end());
      ll tot = 0;
      rep(i, n) tot += r[i];
      int l = n - tot / x;
      need = 0;
      rep(i, l) need += r[i];
    }
    if (need <= k) ans = max(ans, x);
  }

  cout << ans << endl;
  return 0;
}