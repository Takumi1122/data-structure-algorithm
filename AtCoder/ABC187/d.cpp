#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Data = pair<ll, ll>;

int main() {
  int n;
  cin >> n;
  ll x = 0;
  vector<ll> ab(n);
  rep(i, n) {
    ll a, b;
    cin >> a >> b;
    x -= a;
    ab[i] = a + a + b;
  }

  sort(ab.begin(), ab.end());
  ll ans = 0;
  while (x <= 0) {
    x += ab.back();
    ab.pop_back();
    ans++;
  }

  cout << ans << endl;
  return 0;
}