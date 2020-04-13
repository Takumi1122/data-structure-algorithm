#include <bits/stdc++.h>
using namespace std;

long long GCD(long long x, long long y) {
  if (y == 0)
    return x;
  else
    return GCD(y, x % y);
}

int main() {
  int K;
  cin >> K;
  long long res = 0;
  for (int a = 1; a <= K; ++a) {
    for (int b = 1; b <= K; ++b) {
      for (int c = 1; c <= K; ++c) {
        res += GCD(GCD(a, b), c);
      }
    }
  }
  cout << res << endl;
}