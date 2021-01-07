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
  ll n, X;
  cin >> n >> X;
  ll ans = 0;
  rep(i, n) {
    ll x;
    cin >> x;
    ll ab = abs(X - x);
    ans = gcd(ans, ab);
  }

  cout << ans << endl;
  return 0;
}