#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; ++i) cin >> A[i];

  long long res = 0;
  long long two_factor = 1;
  for (int d = 0; d < 60; ++d) {
    long long even = 0, odd = 0;
    for (int i = 0; i < N; ++i) {
      if (A[i] & (1LL << d))
        ++odd;
      else
        ++even;
    }
    long long add = (odd * even) % MOD * two_factor % MOD;
    res = (res + add) % MOD;
    two_factor = (two_factor * 2) % MOD;
  }
  cout << res << endl;
}