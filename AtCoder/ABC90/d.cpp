#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

/*
    1 <= a,b <= N 整数
    b が k 以下の場合は剰余が k 以上となることはないので, b=[k+1,N] で全探索

    k <= x % b を満たす範囲
    ・[k,b-1]
    ・[k+b,2b-1]
    ・  ....
    ・[k+(n-1)b,nb-1]

    N 以下で範囲が全て入る最大の n を計算
    n=(N+1)/b

    小数となる場合は半端な所でNを越えるということに成るので,切り捨てして,前の範囲を指そう
    各範囲で b-k 個の数があるので, (b-k)*n が答えに足される

    あとは, n+1
    の範囲の途中で N があり,一部条件をみたす場合があるので,それを足そう
*/

/*
    参考リンク
    ABC 90 D - Remainder Reminder
      https://atcoder.jp/contests/abc090/tasks/arc091_b
*/

int main() {
  ll n, k;
  cin >> n >> k;

  if (k == 0) {
    ll ans = n * n;
    cout << ans << endl;
    return 0;
  }

  ll ans = 0;
  for (int b = k + 1; b <= n; b++) {
    ll n1 = (n + 1) / b;
    ll d = 0;

    d += 1LL * (b - k) * n1;

    ll l = k + b * n1;
    ll r = n;
    if (l <= r) d += r - l + 1;

    ans += d;
  }

  cout << ans << endl;
  return 0;
}