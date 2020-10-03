#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// A,Bが互いに素ならば、A+B,ABも互いに素

/*
    gcd(a, b) = 1 => gcd(a + b, b) = 1
    よって、A,Bが互いに素ならば、A+B,A も互いに素
    同様に、A,Bが互いに素ならば、A+B,B も互いに素

    一般にm,aが互いに素で、m,bも互いに素であるとき、m,abは互いに素
    よって、A,Bが互いに素ならば、A+B,ABも互いに素
*/

/*
    A′+B′と A′B′が互いに素であることから、gcd(A′+B′,gA′B′) = gcd(A′+B′,g)が成立
*/

/*
    参考リンク
    yukicoder No.442 和と積
      https://yukicoder.me/problems/no/442
*/

ll gcd(ll a, ll b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

int main() {
  ll a, b;
  cin >> a >> b;
  ll g = gcd(a, b);
  a /= g, b /= g;
  cout << g * gcd(a + b, g) << endl;
}