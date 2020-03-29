#include <iostream>
using namespace std;

long long GCD(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return GCD(b, a % b);
}

int main() {
  int N;
  cin >> N;
  long long X;
  cin >> X;
  long long res = 0;
  for (int i = 0; i < N; ++i) {
    long long x;
    cin >> x;
    res = GCD(res, abs(x - X));
  }
  cout << res << endl;
}