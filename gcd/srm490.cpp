#include <iostream>
using namespace std;

long long GCD(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return GCD(b, a % b);
}

class Starport {
 public:
  double getExpectedTime(long long N, long long M) {
    long long g = GCD(N, M);
    N /= g;
    M /= g;
    return (double)(N - 1) * g / 2;
  }
};