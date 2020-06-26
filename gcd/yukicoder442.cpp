#include <iostream>
using namespace std;

long long GCD(long long x, long long y) {
  if (y == 0)
    return x;
  else
    return GCD(y, x % y);
}

int main() {
  long long A, B;
  cin >> A >> B;
  long long g = GCD(A, B);
  A /= g, B /= g;
  cout << g * GCD(A + B, g) << endl;
}