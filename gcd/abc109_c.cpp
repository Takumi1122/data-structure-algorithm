#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// O(n * log(n))
// 最大公約数はO(log(a)) a < b の場合

/*
    3 個以上の値の最大公約数を求める
    ・res = 0 と初期化
    ・各iに対して res = gcd(res, x[i]) と更新する
*/

/*
    参考リンク
    ABC 109 C - Skip
      https://atcoder.jp/contests/abc109/tasks/abc109_c
*/

ll gcd(ll a, ll b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

int main() {
  int n;
  cin >> n;
  ll x;
  cin >> x;
  ll res = 0;
  rep(i, n) {
    ll xi;
    cin >> xi;
    res = gcd(res, abs(xi - x));
  }
  cout << res << endl;
}