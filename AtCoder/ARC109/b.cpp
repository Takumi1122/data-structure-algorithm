#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  ll n;
  cin >> n;

  ll ans = n;
  ll cnt = 0;
  ll n1 = n + 1;
  ll x = 1;

  while (n1 - x >= 0) {
    n1 -= x;
    x++;
    cnt++;
  }
  cnt--;
  ans -= cnt;

  cout << ans << endl;
  return 0;
}