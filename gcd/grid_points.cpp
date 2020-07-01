#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll gcd(ll a, ll b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

int main() {
  ll ax, ay, bx, by;
  cin >> ax >> ay >> bx >> by;
  cout << gcd(abs(ax - bx), abs(ay - by)) - 1 << endl;
}