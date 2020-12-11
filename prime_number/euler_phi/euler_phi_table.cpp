#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// オイラー関数値 O(√n)
// 正の整数Nが与えられたとき、1,2,…,Nのうち
// Nと互いに素であるものの個数をφ(N)と表します。これをオイラー関数とよびます。
// φ(N) = N((p1 - 1) / p1)((p2 - 1) / p2)...((pk - 1) / pk)

// euler_phi_table(n): n以下のオイラー関数テーブルを返す
// O(n * loglog(n))
vector<int> euler_phi_table(int n) {
  vector<int> euler(n + 1);
  for (int i = 0; i <= n; i++) {
    euler[i] = i;
  }
  for (int i = 2; i <= n; i++) {
    if (euler[i] == i) {
      for (int j = i; j <= n; j += i) {
        euler[j] = euler[j] / i * (i - 1);
      }
    }
  }
  return euler;
}