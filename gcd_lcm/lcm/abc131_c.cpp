#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    「A以上B以下の整数のうち〜を満たすものの個数を求めよ」という問題では
    (B以下の整数のうちの〜を満たすものの個数)-(A-1以下の整数のうちの〜を満たすものの個数)
*/

/*
    参考リンク
    ABC 131 C - Anti-Division
      https://atcoder.jp/contests/abc131/tasks/abc131_c
*/

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll f(ll x, ll c, ll d) {
  ll res = x;
  res -= x / c;
  res -= x / d;
  res += x / lcm(c, d);
  return res;
}

int main() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;

  ll ans = f(b, c, d) - f(a - 1, c, d);
  cout << ans << endl;
  return 0;
}