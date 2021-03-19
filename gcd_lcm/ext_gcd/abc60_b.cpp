#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    // べズーの等式
    整数Nが整数 x,yを用いてax+byの形に表せる必要十分条件は、
    Nがgcd(a,b)の倍数であることである
*/

/*
    参考リンク
    ABC 060 B - Choose Integers
      https://atcoder.jp/contests/abc060/tasks/abc060_b
*/

ll gcd(ll a, ll b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

int main() {
  ll a, b, c;
  cin >> a >> b >> c;
  if (c % gcd(a, b) == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}