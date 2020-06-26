#include <iostream>
using namespace std;

long long GCD(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return GCD(b, a % b);
}

int main() {
  long long A, B;
  cin >> A >> B;
  cout << A / GCD(A, B) * B << endl;
}