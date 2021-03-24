#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

ll f(ll x) {
  string s = to_string(x);
  return stoll(s + s);
}

int main() {
  ll n;
  cin >> n;
  ll x = 1;
  while (f(x) <= n) ++x;
  ll ans = x - 1;
  cout << ans << endl;
  return 0;
}