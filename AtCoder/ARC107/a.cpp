#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll mod = 998244353;

int main() {
  ll a, b, c;
  cin >> a >> b >> c;
  ll sa = (a * (a + 1) / 2) % mod;
  ll sb = (b * (b + 1) / 2) % mod;
  ll sc = (c * (c + 1) / 2) % mod;

  ll ans = sa * sb % mod * sc % mod;
  cout << ans << endl;
  return 0;
}