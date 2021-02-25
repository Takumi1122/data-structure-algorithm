#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// O(log(a)) a < b の場合
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
  int n;
  cin >> n;
  ll ans = 1;
  rep(i, n) {
    ll t;
    cin >> t;
    ans = lcm(ans, t);
  }
  cout << ans << endl;
  return 0;
}