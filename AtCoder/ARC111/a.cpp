#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// floor(10^n/m) % m を求める

/*
    参考リンク
    ARC 111 A - Simple Math 2
      https://atcoder.jp/contests/arc111/tasks/arc111_a
*/

// a^n mod を計算する
ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main() {
  ll n, m;
  cin >> n >> m;
  ll ans = (modpow(10, n, m * m) / m) % m;
  cout << ans << endl;
  return 0;
}