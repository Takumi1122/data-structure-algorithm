#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MOD = 1000000007;

int main() {
  ll a, b, c;
  a = 111;
  b = 123;
  c = 987;
  cout << a * b * c % MOD << endl;
  cout << a * b % MOD * c % MOD << endl;

  cout << a * b % MOD << endl;
  cout << (a % MOD) * (b % MOD) % MOD << endl;

  cout << (a + b) % MOD << endl;
  cout << ((a % MOD) + (b % MOD)) % MOD << endl;
}