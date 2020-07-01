#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
  int n;
  ll z;
  cin >> n >> z;
  ll res = 1;
  rep(i, n) {
    ll a;
    cin >> a;
    ll g = gcd(z, a);
    res = lcm(res, g);
  }
  cout << res << endl;
}