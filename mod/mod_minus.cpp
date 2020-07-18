#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MOD = 1000000007;

// 負の数にも対応した % 演算
ll mod(ll val, ll m) {
  ll res = val % m;
  if (res < 0) res += m;
  return res;
}

int main() {
  int a = 2000000020;
  int b = 20;

  cout << "普通に計算して余りを求める: " << (a - b) % MOD << endl;
  cout << "余り求めてから計算して余りを求める: "
       << ((a % MOD) - (b % MOD)) % MOD << endl;
  cout << "余り求めてから計算して余りを求める (対策済): "
       << mod((a % MOD) - (b % MOD), MOD) << endl;
}