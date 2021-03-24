#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// a^n を計算する
ll pow_ll(ll a, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a;
    a = a * a;
    n >>= 1;
  }
  return res;
}

int main() {
  ll n;
  cin >> n;
  string s = to_string(n);
  ll sz = s.size();
  if (sz % 2 == 1) {
    ll ans = 0;
    for (int i = 2; i <= sz; i += 2) {
      ans += 9 * pow_ll(10, i / 2 - 1);
    }
    cout << ans << endl;
    return 0;
  } else {
    ll ans = 0;
    for (int i = 2; i <= sz - 2; i += 2) {
      ans += 9 * pow_ll(10, i / 2 - 1);
    }
    string s1 = s.substr(0, sz / 2);
    string s2 = s.substr(sz / 2);
    ll a1 = stoll(s1);
    ll a2 = stoll(s2);
    if (a1 <= a2) {
      ans += a1 - pow_ll(10, sz / 2 - 1) + 1;
    } else {
      ans += a1 - pow_ll(10, sz / 2 - 1);
    }
    cout << ans << endl;
    return 0;
  }
  return 0;
}